#include <iostream>
#include <string>
#include <thread>
#include <vector>

// Simulated external market API response
struct ExecutionResult {
    bool isSuccess;
    int systemTicketId;
};

// --- Core Threaded Order Routing Engine ---
class OrderCoordinator {
private:
    int globalTicketSequence;
    bool isBrokerConnectionBusy;

public:
    OrderCoordinator() {
        globalTicketSequence = 1000;
        isBrokerConnectionBusy = false;
    }

    // Buggy Multi-Threaded Execution Call
    ExecutionResult RouteOrderToBroker(std::string symbol, std::string orderType, double size) {
        ExecutionResult result;
        result.isSuccess = false;
        result.systemTicketId = -1;

        // CRITICAL CHECK: Don't allow overlapping packets on the network wire
        if (isBrokerConnectionBusy) {
            std::cout << "[REJECTED] Network pipe flooded! Order dropped for: " << symbol << "\n";
            return result;
        }

        // Lock the pipe state
        isBrokerConnectionBusy = true;

        std::cout << ">>> [ROUTING] Sending " << orderType << " " << size << " lots of " << symbol << " to broker...\n";
        
        // Simulate network latency delay to broker server (100ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Generate the unique system tracking ticket
        globalTicketSequence++; 
        
        result.systemTicketId = globalTicketSequence;
        result.isSuccess = true;

        std::cout << "<<< [FILLED] Order complete for " << symbol << ". Ticket assigned: #" << result.systemTicketId << "\n";
        
        // Free the connection pipe
        isBrokerConnectionBusy = false;
        return result;
    }
};

// Global resource accessible by multiple threads
OrderCoordinator globalCoordinator;

// Thread worker task function
void SimulateAsynchronousBot(std::string symbolName, std::string direction) {
    // Attempt to fire an independent order on this thread
    globalCoordinator.RouteOrderToBroker(symbolName, direction, 0.02);
}

// --- Simulator Main ---
int main() {
    std::cout << "--- STARTING MULTI-THREADED GTI SENTINEL ENGINE ---\n\n";

    // Scenario: Three completely independent bot threads fire trades at the EXACT same time
    // Thread 1 monitors USDJPY, Thread 2 monitors EURUSD, Thread 3 monitors GBPUSD
    std::thread thread1(SimulateAsynchronousBot, "USDJPY", "BUY");
    std::thread thread2(SimulateAsynchronousBot, "EURUSD", "SELL");
    std::thread thread3(SimulateAsynchronousBot, "GBPUSD", "BUY");

    // Wait for all asynchronous system threads to finish execution before exiting main
    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "\n--- ALL THREADS RETURNED. ENGINE STABLE ---\n";
    return 0;
}