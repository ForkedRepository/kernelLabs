= Misc Driver
== First Driver
Write a misc driver that will:
* Use a dynamic minor number
* implement read and write function
* show up in /dev/fogale
* when readed from, it should return the "fogale" String
* when written, data should be checked. It will return a correct value if it matches "fogale" or return an "invalid value" error
* The misc device should be registered when your module is loaded, and unregistered when it is unloaded
* When loadded the module should print the used minor


