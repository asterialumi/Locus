# Locus
Some of the fundamental data structures are: a **List** (array or linked list), a **Tree**, a **Graph**, and a **Map**. But what if we wanted to model just one data structure that can be shaped to any of these, and possibly more? What if you had one array that has the best possible quality-of-life functions, and it acts as a storage to any other specialized structures you need for your project? Hey, that screams like **Data-Oriented Design**! (I JUST learned about this btw)

Introducing **Locus**, a data structure / data type I designed that is cursor-based, which works similarly to c++'s `std::vector`, but with features I designed for more freedom and separation of responsibility. (Previously named as: **Canvas**)

It's not only a vector, but a universal storage you can use for any other stuctures you might use it for. It's designed to be as semantic as possible, and EVERY function is one word. It's purpose is also heavily influenced for game development, since Locus is essentially an **Array-based implementation** of data structures without using pointers (i.e. it's cache friendly :D).

Here are some of it's features:

- Initialize as `Locus<T>` and you've created yourself a simple **Array**. If you want a Tree or any other data structure, you can initialize it by using the `view()` function!
```cpp
    lumi::Locus<char> example(10, 'A');

    auto tree = example.view<lumi::Tree>(); //returns a Tree "Aspect" of type char (automatic, since your 'example' locus is of type char already)
    tree.display();
```
- Uses `struct Point<T>`, which works similary to iterators in c++, except most functions in Locus returns a Point by default, so you can do **Cursor Chaining**. Examples:
 ```cpp
    using namespace lumi;
    Locus<int> locus;

    auto cursor = locus.at(4); //you are free to point at an invalid index
    for(int i = 0; i < 5; i++) cursor.insert(i+1); //automatically creates default ints (0) before index 4
    locus.at(5).insert(10);

    Locus<Person> people;
    people.build("Asteria", 20).move(2); //move() is still unimplemented
```

- Need a range of Points? Use `struct Chain<T>`!
    - ex. `locus.range(locus.begin(), locus.end()).remove(5);`
    - *this removes elements that are equal to 5 within the range locus[0] to locus[size-1], which are `locus.begin()` and `locus.end()` respectively*
- and many more... I'll care to update this once I get motivated.


### Not yet completed
- a LOT of data structures as `Aspects`, which are still unimplemented
- a lot of design problems I have yet to solve, send help
- error handling and more code documentation

### How to use
For now, you can really just take a look and download the source code, which are the files inside the `include\lumi` folder. I use the `main.cpp` (and recently, `newmain.cpp`) for testing the code under `examples`. Keep in mind that some of these naming conventions might not have changed yet, since I recently renamed this project from **Canvas** to **Locus** to better represent my new design, as well as to avoid further naming collisions.

Anyways, just include the header "Locus.hpp" and you should be good to go. Have fun experimenting!