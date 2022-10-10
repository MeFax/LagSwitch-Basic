#include <windows.h> 
#include <string>
#include <thread>

std::string rule_name = "LagMe";

int main()
{
    bool AFlood = false;
    while (true) {
        std::string cmd = "netsh advfirewall firewall delete rule name=\"" + rule_name + "\"";
        if (GetAsyncKeyState(VK_RMENU)) {
			// create rule to block outbound
            if(AFlood == true) {
                cmd = "netsh advfirewall firewall add rule name =\"" + rule_name + "\" protocol=any dir=out action=block";
                WinExec(cmd.c_str(), 0);
                cmd = "netsh advfirewall firewall add rule name =\"" + rule_name + "\" protocol=any dir=in action=block";
                WinExec(cmd.c_str(), 0);
                AFlood = false;
            }
        }
        else {
            if (AFlood == false) {
                cmd = "netsh advfirewall firewall delete rule name=\"" + rule_name + "\"";
                WinExec(cmd.c_str(), 0);
                AFlood = true;
            }
        }
    }
}