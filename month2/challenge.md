The Scenario
You are interviewing for a Senior Core Developer role at a high-frequency proprietary trading firm. The firm uses a centralized RiskGateway to validate orders from multiple independent trading bots before they are routed to the market.

If the firm's global daily loss limit is breached, the gateway must instantly shut down all routing to protect the firm's capital.

The Buggy Code (SovereignRisk.cpp)

Your Offline Mission Metrics
Find the 3 structural engineering vulnerabilities hidden inside this script:

The "Poisoned Order" Memory Leak / State Desynchronization Bug: Look closely at ValidateOrder. What happens to the internal combinedCurrentLoss value when a trade triggers the circuit breaker condition? Does that math make sense for a gateway?

The Polymorphism "Slicing" and Interface Failure: Look at the base class method declarations and the data fields. There is a missing C++ implementation standard in how the pointers or strings are accessed that limits standard scalability.

The Object Lifecycle Leak: Look at the main() function cleanup routines. You deleted the vector components, but what critical global memory block was left open in memory when the program terminates?


The Scenario: The "Telaviv Pulse" Network Buffer
Your Telegram bot gateway (Telaviv) streams market updates over the network using WebRequest. In production, if your connection drops or slows down, sending messages one-by-one blocks the main trading thread, causing massive delays in your execution.

To fix this, you write a high-performance Message Queue Buffer that collects trade logs in memory and flushes them to the network in a single batch. However, the junior developer who wrote the initial prototype left 3 critical architectural and memory bugs that will crash the system under heavy market volatility.

The Buggy Code (TelavivPulse.cpp)

Your Offline Mission Metrics
Analyze this file side-by-side with your first challenge today. Find these 3 engineering vulnerabilities:

Bug 1: The Undefined Array Deallocation Flaw
Look inside the class destructor ~NetworkBuffer(). It uses delete storageArray;.

The Threat: storageArray was allocated using new[] (the array allocation operator). Using a single-object delete on an array pointer causes undefined behavior, corrupts the heap memory, and will cause your app to crash randomly in live trading.

What to fix: Find the correct C++ syntax to delete an allocated array memory block.

Bug 2: The Silent Data Corruption / Buffer Re-use Bug
Look at Simulation 4. After calling FlushNetwork(), currentCount goes back to 0. Then you call Enqueue(104, ...).

The Threat: Look at the internal state of the array. Does storageArray[0] get completely cleared out, or does the old text from message 101 still linger underneath? If a network error happens mid-flush on the second run, what data will the bot accidentally resend?

What to fix: Implement a memory-clearing initialization step inside the enqueue or flush cycles.

Bug 3: The System Copy Vulnerability (Deep vs. Shallow Copy)
This class handles raw pointer allocation (MessagePacket* storageArray) but does not explicitly delete or define a Copy Constructor or Assignment Operator.

The Threat: If another developer accidentally duplicates your buffer instance in their code (e.g., NetworkBuffer secondaryBuffer = *pulseBuffer;), both objects will point to the exact same memory address. When one object goes out of scope, it deletes the array, leaving the other object pointing to dead space (a dangling pointer).

What to fix: Research how to apply the C++ "Rule of Three" to secure raw pointer classes, or use modern C++ keywords to explicitly disable copying.



The Scenario: The "GTI Sentinel" Multi-Threaded Order Router
In your trading system, you want to scale up from trading just USDJPY to monitoring multiple currency pairs simultaneously. To prevent the execution of one pair from lagging the others, you create an asynchronous Order Processing Thread for each asset.

To coordinate these independent threads and prevent them from sending conflicting trade packets to your broker at the exact same millisecond, you write an Order Coordinator class. However, the multi-threaded code contains 3 massive concurrent engineering bugs that will freeze your trading engine or corrupt your account memory under live fast-market conditions (like the NY Open).

The Buggy Code (GazingSentinel.cpp)

Your Offline Mission Metrics
Analyze this file side-by-side with the Telaviv Pulse today. Find these 3 concurrent engineering bugs:

Bug 1: The "Check-Then-Act" Race Condition
Look at how isBrokerConnectionBusy is checked and then changed:
if (isBrokerConnectionBusy) { ... }
isBrokerConnectionBusy = true;

The Threat: If Thread 1 and Thread 2 hit the if statement at the exact same millisecond, both will see it is false. Both threads will bypass the safety check, both will set it to true, and both will try to push data down the pipe simultaneously. This is a classic Race Condition.

What to fix: You need a mechanism that makes the check and the lock operation completely atomic. Research C++ std::mutex and std::lock_guard.



Bug 2: The Ticket ID Data Corruption (Non-Atomic Increment)
Look at how the unique tracking identifier is generated:
globalTicketSequence++;

The Threat: In C++, a standard int++ operation is not atomic. Under the hood, it takes 3 steps: read the value from CPU memory, add 1, write it back. If two threads read the memory address at the same time, they will generate the exact same tracking ticket ID for different trades! This will completely desynchronize your MQL5 database mapping.

What to fix: Research how to make a variable thread-safe using std::atomic<int>.


Bug 3: The Dead End "Stuck Lock" Exception Vulnerability
Look closely at what happens if a runtime exception or crash occurs mid-execution inside the network delay simulation block before isBrokerConnectionBusy = false; is reached.

The Threat: If the execution breaks midway, the variable stays true forever. The system will permanently lock up, and every single subsequent trade for the rest of the day will be rejected.

What to fix: Use RAII (Resource Acquisition Is Initialization) memory wrappers to ensure a lock automatically opens when a function scope finishes execution, regardless of crashes.