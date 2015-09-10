= List and Thread
== Deal with list
* define a `struct identity` having those 2 fields:
        char name[20];
        int id;

* Declare a static variable that points to a list of these indentity
* Write a function `identity_create(char * name, int id)` that create a `struct identity`, copy the name value, and set the id. The new structure should be added to the list. Return 0 on success, error otherwise.
* Write a function `identity_find(int id)` that return the structure associated wiht this id, NULL otherwise
* Write a function `identity_destroy(int id)` that remove the structure associated with this id form the list.

* The module init should look like

        struct identity *temp;

        identity_create("Alice", 1);
        identity_create("Bob", 2);
        identity_create("Dave", 3);
        identity_create("Gena", 10);

        temp = identity_find(3);
        pr_debug("id 3 = %s\n", temp->name);

        temp = identity_find(42);
        if (temp == NULL)
                pr_debug("id 42 not found\n");
        else
                pr_debug("oops\n");

== Add a Thread
