# LagSwitch Basic With C++

# How Use ?

> Press `Right ALT`
> `Application` Adding basic `Firewall rules` 
```
if (GetAsyncKeyState(VK_RMENU)) {
  ... = "netsh advfirewall firewall add rule name =\"" + rule_name + "\" protocol=any dir=out action=block";
  ... = "netsh advfirewall firewall add rule name =\"" + rule_name + "\" protocol=any dir=in action=block";

else {
  ... = "netsh advfirewall firewall delete rule name=\"" + rule_name + "\"";
```

`#Includes`
```
#include <windows.h> 
#include <string>
```
