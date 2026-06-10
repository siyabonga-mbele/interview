#include <iostream>
#include <vector>
#include <string>

// --- Base System Class ---
class TradingBot {
protected:
    std::string botName;
    double currentDrawdown;
public:
    TradingBot(std::string name, double initialDrawdown) {
        botName = name;
        currentDrawdown = initialDrawdown;
    }
    
    std::string GetName() { return botName; }
    double GetDrawdown() { return currentDrawdown; }
    
    // Virtual execution simulation
    virtual bool RequestTradeExecution(double riskAmount) {
        std::cout << "[" << botName << "] Requesting trade with risk: $" << riskAmount << "\n";
        return true;
    }
};

// --- Central Risk Architecture (Singleton Pattern) ---
class RiskGateway {
private:
    static RiskGateway* instance;
    double globalMaxLossLimit = 5000.00; // Hard cap: $5,000 max global loss allowed
    double combinedCurrentLoss = 0.00;
    bool isSystemLocked = false;

    RiskGateway() {} // Private constructor for Singleton

public:
    static RiskGateway* GetInstance() {
        if (instance == nullptr) {
            instance = new RiskGateway();
        }
        return instance;
    }

    // High-performance check before routing order to market API
    bool ValidateOrder(TradingBot* bot, double orderRisk) {
        if (isSystemLocked) {
            std::cout << "CRITICAL ALERT: Order Rejected. Global Risk Circuit Breaker Active!\n";
            return false;
        }

        // Add the incoming order's risk to our ledger tracking
        combinedCurrentLoss += orderRisk;

        // Verify if this order breaches our maximum firm tolerance
        if (combinedCurrentLoss >= globalMaxLossLimit) {
            isSystemLocked = true; 
            std::cout << "!!! CIRCUIT BREAKER TRIGGERED !!! Total Risk: $" << combinedCurrentLoss << "\n";
            return false;
        }

        return true;
    }
};

// Initialize static member of Singleton
RiskGateway* RiskGateway::instance = nullptr;

// --- Specialized Trading Bot Implementation ---
class GoldScalper : public TradingBot {
private:
    double MaxSpreadLimit = 3.0; // Max allowed spread in pips
public:
    GoldScalper(std::string name, double drawdown) : TradingBot(name, drawdown) {}

    bool RequestTradeExecution(double riskAmount) override {
        TradingBot::RequestTradeExecution(riskAmount);
        
        // Fetch the global risk manager instance
        RiskGateway* riskCenter = RiskGateway::GetInstance();
        
        // Audit the order through the gate
        return riskCenter->ValidateOrder(this, riskAmount);
    }
};

// --- Main Testing Simulator ---
int main() {
    RiskGateway* securityGate = RiskGateway::GetInstance();
    
    // Instantiate our portfolio tracking vector using pointers
    std::vector<TradingBot*> portfolio;
    portfolio.push_back(new GoldScalper("MAGOLIDE_ALPHA", 120.50));
    portfolio.push_back(new GoldScalper("TELAVIV_SENTINEL", 450.00));

    std::cout << "--- STARTING LIVE MARKET ROUTING SIMULATION ---\n\n";

    // Simulation Sequence 1: Normal Operation
    portfolio[0]->RequestTradeExecution(2000.00); 
    
    // Simulation Sequence 2: High Volatility Event (This trade should hit the limit exactly)
    portfolio[1]->RequestTradeExecution(3000.00); 

    // Simulation Sequence 3: This trade happens AFTER the circuit breaker triggers!
    bool result = portfolio[0]->RequestTradeExecution(500.00);
    
    if(result) {
        std::cout << "SUCCESS: Order reached the market.\n";
    } else {
        std::cout << "FAILURE: Order blocked securely.\n";
    }

    // Cleanup memory allocations
    for (TradingBot* bot : portfolio) {
        delete bot;
    }

    return 0;
}