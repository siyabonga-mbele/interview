#include <iostream>
#include <string>

// --- Individual Message Packet ---
struct MessagePacket {
    int messageId;
    std::string payload;
};

// --- Ring Buffer Queue for High-Speed Storage ---
class NetworkBuffer {
private:
    MessagePacket* storageArray;
    int capacity;
    int currentCount;

public:
    NetworkBuffer(int maxCapacity) {
        capacity = maxCapacity;
        currentCount = 0;
        // Allocate dynamic array for the packet buffer
        storageArray = new MessagePacket[capacity];
    }

    // Buggy Destructor
    ~NetworkBuffer() {
        delete[] storageArray; 
    }

    // Push an incoming alert packet into the buffer
    bool Enqueue(int id, std::string alertText) {
        if (currentCount >= capacity) {
            std::cout << "BUFFER OVERFLOW: Telemetry dropped! ID: " << id << "\n";
            return false;
        }

        // Add packet to the array
        storageArray[currentCount].messageId = id;
        storageArray[currentCount].payload = alertText;
        currentCount++;
        return true;
    }

    // Flush and broadcast all messages to the Telegram API
    void FlushNetwork() {
        std::cout << "\n--- FLUSHING " << currentCount << " PACKETS TO TELEGRAM API ---\n";
        
        for (int i = 0; i < currentCount; i++) {
            std::cout << "Sending [" << storageArray[i].messageId << "]: " << storageArray[i].payload << "\n";
            // Network logic simulation happens here...
        }
        
        // Reset count after flushing the data
        currentCount = 0; 
    }
};

// --- Simulator Track ---
int main() {
    std::cout << "--- INITIALIZING TELAVIV PULSE ENGINE ---\n";
    
    // Create a network buffer with space for exactly 2 packets
    NetworkBuffer* pulseBuffer = new NetworkBuffer(2);

    // Simulation 1: Packet inputs arrive smoothly
    pulseBuffer->Enqueue(101, "USDJPY Entry: Buy @ 156.40");
    pulseBuffer->Enqueue(102, "USDJPY Target: TP1 Hit @ 156.55");

    // Simulation 2: Sudden market spike causes a third message before the flush
    pulseBuffer->Enqueue(103, "CRITICAL: Trailing Stop Active");

    // Simulation 3: Broadcast data to clear the runway
    pulseBuffer->FlushNetwork();

    // Simulation 4: Re-using the buffer after the flush
    pulseBuffer->Enqueue(104, "GBPUSD Signal Detected");

    // System shutdown
    delete pulseBuffer;
    std::cout << "\n--- ENGINE SHUT DOWN CLEANLY ---\n";
    return 0;
}