
## question 1:  When to use Stack allocation vs Heap Allocation? 

STACK ALLOCATION:
```Car car1```

HEAP ALLOCATION:
```Car* car1 = new Car()```

Stack allocation: 
1. Memory is allocated on the stack
2. Automatically destroyed when the objects goes out of scope
3. Use dot operator to access methods and values
4. No manual memory management needed
5. Safer (no memory leaks)
6. Stack is faster than heap (so faster allocation and de-allocation)
7. CANNOT easily pass the ownership of the objects across scopes

Heap Allocation:
1. Memory is allocated on the heap
2. Must call "delete car1" manually, else it will use memory and cause memory leak issue
3. Use -> operator to access entities
4. Necessary when you want to object to outlive the function/scope
5. Needed for polymorphic behaviour


## question 2: what is unique_ptr in modern C++?

## question 3: inheritance? 
-> 
```class DerivedClass : mode_of_inheritance BaseClass {
    // Body of the Derived Class
};
```
public, protected, private (both public and protected members of the base class will become private in the deireved class. it is the default mode)
-> to access private members of the parent class (base class) we have to use getter and setters functions and keep them as public.
-> TYPES: SINGLE, MULTILEVEL, MULTIPLE, HEIRARCHICAL, HYBRID

## what is static keyword?
-> static members belong to the class and not the objects. static members from the base class are not inherited by the derieved class in the traditional way. It is initialized before any object(even the main class itself). it is useful in maintaining data shared among all instances of a class.

## friend function and classes?
-> allows access to private and protected memebers of the class. 

## Prevent memory leaks?
-> In serious coding (production level), memory leaks are a disaster 🧨, so rule is:

If you `new`, you must `delete`.
If you `malloc`, you must `free`.

