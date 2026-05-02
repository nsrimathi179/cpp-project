#include <iostream>
#include <map>
using namespace std;

class ConfigManager {
private:
    map<string, string> config;
    static ConfigManager* instance;

    ConfigManager() {
        config["theme"] = "dark";
        config["language"] = "en";
        config["version"] = "1.0.0";
    }

public:
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    static ConfigManager* getInstance() {
        if (!instance)
            instance = new ConfigManager();
        return instance;
    }

    void set(string key, string value) {
        config[key] = value;
    }

    string get(string key) {
        if (config.count(key))
            return config[key];
        return "Not found";
    }

    void displayAll() {
        for (auto& kv : config)
            cout << kv.first << " = " << kv.second << endl;
    }
};

ConfigManager* ConfigManager::instance = nullptr;

int main() {
    ConfigManager* cm1 = ConfigManager::getInstance();
    ConfigManager* cm2 = ConfigManager::getInstance();

    cout << "Same instance: " << (cm1 == cm2 ? "Yes" : "No") << endl;
    cm1->set("theme", "light");
    cm2->displayAll();
    return 0;
}
