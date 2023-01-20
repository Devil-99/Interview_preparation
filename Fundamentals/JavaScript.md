## 1. What is Event Loop ?
[Youtube Link](https://www.youtube.com/watch?v=EI7sN1dDwcY&ab_channel=JavaBrains)

Basically javascript maintains a event queue to store all the work systematically as it is a single threaded model. And **Event Loop** is a loop that runs untill the queue is being empty and all processes are got executed.

The event loop is actually composed of one or more event queues. In each queue, events are handled in a FIFO order. It's up to the browser to decide how many queues to have and what form of prioritisation to give them. There's no Javascript interface to individual event queues or to send events to a particular queue.

If 2 asynchronous process with a setTime and promise comes in event loop at the same time. Then the promise will have the higher priority.

## 2. What is promise ?
A Promise is a proxy for a value not necessarily known when the promise is created. It allows you to associate handlers with an asynchronous action's eventual success value or failure reason. This lets asynchronous methods return values like synchronous methods: instead of immediately returning the final value, the asynchronous method returns a promise to supply the value at some point in the future.

### 2.1. Promise vs Async-Await.
Promise is a technique that gives you the functionality of a synchronous function to a asynchronous function. It waits for the completion of the promise function, and then execute the next thing.

Async-Await is just a syntactic sugar over promise, a wrapper of code executes for synchronously.  
Using Async/Await makes it easier to read and understand the flow of the program as compared to promise chains.
### 2.2. Promise vs callback.
To implement asynchronous code in JavaScript we use callback functions and promises. A callback function is passed as an argument to another function whereas Promise is something that is achieved or completed in the future. In JavaScript, a promise is an object and we use the promise constructor to initialize a promise.

## 4. Let vs Var ?
* The main difference is scoping rule. **Let** is introduced in ES6. Variables declared with **Var** keyword has the function scope or global scope.It is scoped to the immediate function body. Where as **let** keyword has the block scope, It only works under enclosing block.
* 2 **var** declaration in a same scope does not give any error, one overwrites another. But 2 **let** declaration in same scope gives error.
* We can use hosting with **var** but not wuth **let**.

## 5. setTimeout vs setInterval ?
* setTimeout runs the code/function ***once*** after the timeout.
* setInterval runs the code/function ***repeatedly***, with the length of the timeout between each repeat.

## 6. Most common ES6 features / What are the ES6 features you have used ?
* **let** and **const** keyword.
* Arrow Function.
* String literals, Template literals.
* Promises.
* Classes.
* Modules.

## 7. What is rest variable ?

The rest parameter has to be the last argument because it is used to collect all of the remaining elements into an array.

    function show(...rest) {  
    let sum = 0;  
    for (let i of rest) {  
        sum += i;  
    }  
    console.log("Sum = "+sum);  
    }  
    
    show(10, 20, 30); 

    // output will be 60.

## 8. Shallow Copy vs Deep Copy
Shallow Copy stores the references of objects to the original memory address. It stores the copy of the original object and points the references to the objects. Hence, it reflects changes made to the copied object in the original object.

Deep Copy stores copies of the object's value. Hence, the changes only reflects on the copied object, not on the original object.

## 9. Difference between **map** and **reduce** ?
**map** takes a callback and runs it over every element on the array but what makes it unique is that it makes a new array based on the existing array.

    var arr = [1, 2, 3];

    var mapped = arr.map((elem)=>{
        return elem * 10;
    })

    console.log(mapped); // it genrate new array

**Reduce** method of the array object is used to reduce the array to one single value.

    var arr = [1, 2, 3];

    var sum = arr.reduce((sum, elem)=>{
        return sum + elem;
    })

    console.log(sum) // reduce the array to one single value

-[stackoverflow](https://stackoverflow.com/questions/49934992/main-difference-between-map-and-reduce#:~:text=one%20by%20one.-,Map,-Map%20takes%20a)

## 10. Middlware
It is a function that is applied before any routes.  
Sometimes we need to execute something before routing to another page like authentication etc. Then we use middleware.

A middleware has 3 arguments request, response, nextFunction(). The page will continue loading until the nextFunction get exected.

