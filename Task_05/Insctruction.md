= Debug FS
== Improve Task 4 Driver
* Take the driver of the Task 4 and modify it to create a directory fogale in debugfs.
In that directory create a file 'secret'.

* The 'secret' file needs to be writable only by root. When writing to it, the value must be stored up to one page of data. The content could be read by anyone.
* Make sure that reading for this file while someone it writing it behave correctly
* On onloading clean debugfs, memory ...

