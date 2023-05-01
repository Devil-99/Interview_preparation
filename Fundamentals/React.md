# 1. Why use Functional component not Class component?
- Understanding this keyword in class component is very different than other language.
- Remember to [bind event handlers](https://www.youtube.com/watch?v=kVWpBtRjkCk&ab_channel=Codevolution).
- Classes don't minify very well and make hot reloading very unreliable.

Previously React functional component was stateless component with no Life Cycle methods compatible. But after introducing Hook concept it has changed.
- Hooks helps us to allowing use stateful logic without tempering the component structure. And also allow us to use Life Cycle methods.

*Though a stateless component can render props.*

## Why **Binding Event Handler** is requied in React ?
It is because of this keyword in class component. This is not a property of React but of Javascript 'this' keyword.     
While using event handler, 'this' keyword will return undefine. That's why binding is required.We have to bind the keyword 'this'.  
ex.-
"onClick={ this.clickHandler.bind(this) }" /
"onClick={ ( )=> this.clickHandler }"

Binding happens once in every render. So, it is preferable to bind inside constructor rather inside render method.
Or we can use binding by defining the handler as an callback arrow function.

# 2. React State and  Props.
**React states** are mutable variable defined under react components.These are changed by useState/setState hooks.  

**React props** are like arguments passed through components.So that we can use same component for multiple values.

Video link - [SimpliLearn](https://www.simplilearn.com/what-is-reactjs-props-article#:~:text=In%20ReactJS%2C%20the%20props%20are,components%20are%20read%2Donly%20components.)

### **State vs Props**:
- State is more likely variable used under react component where Prop is argument(Function parameter) passed to component from outside(other component).
- Props are immutable. States are mutable.

# 3. Lifecycle method of React.
### **Mounting :**
Each component in React has a lifecycle which you can monitor and manipulate during its three main phases.
The three phases are: ***Mounting, Updating, and Unmounting***.

Mounting means putting elements into the DOM.
React has four built-in methods that gets called, in this order, when mounting a component:

- constructor()
- getDerivedStateFromProps()
- render()
- componentDidMount()

The render() method is required and will always be called, the others are optional and will be called if you define them.

### **Updating :**
This phase in the lifecycle is when a component is updated.
A component is updated whenever there is a change in the component's state or props.

React has five built-in methods that gets called, in this order, when a component is updated:

- getDerivedStateFromProps()
- shouldComponentUpdate()
- render()
- getSnapshotBeforeUpdate()
- componentDidUpdate()

The render() method is required and will always be called, the others are optional and will be called if you define them.

### **Unmounting :**
This phase in the lifecycle is when a component is removed from the DOM, or unmounting as React likes to call it.

React has only one built-in method that gets called when a component is unmounted:

componentWillUnmount()

# 4. React Hooks.
Hooks are the feature which allow you to use React features and life cycle methods without writing as a class component.

[Link](https://www.codingninjas.com/codestudio/library/top-react-hooks-interview-questions)

### **useState -** 
- Used to change state value.
- asynchronous process. If you want to do something just after state change, use callback function/async/promise.

### **useEffect -**
- In class components, we have lifecycle methods to perform actions in a specific lifecycle stage of our component. For us to do something similar and perform side effects in our functional components, the React team created the useEffect Hook.
- The useEffect Hook is called after every render of our component.


# 5. What is event.target.value in React exactly ?
* [event.target](https://stackoverflow.com/questions/67014481/what-is-event-target-value-in-react-exactly) gives you the element that triggered the event. So, **event.target.value** retrieves the value of that element (an input field, in my example).

* In React, events are [SynthenticEvent](https://reactjs.org/docs/events.html), a wrapper around the browser’s native event.
* It has the same interface as the browser’s native event, including stopPropagation() and preventDefault(), except the events work identically across all browsers.

# 6. What is forwardRef in React ?
* The [forwardRef](https://stackoverflow.com/questions/66664209/how-can-i-use-forwardref-in-react) api, (coupled with the useImperativeHandle hook) lets you customize how and where your refs are placed inside your custom components. Also, forwardRef is the only way to pass a ref to your custom function components.

*  Refs can't be passed to function components, because They don't have instances! The only way to pass a ref to a function component is using forwardRef. When using forwardRef, you can simply pass the ref to a DOM element, so the parent can access it, or you could create an object with fields and methods using the useImperativeHandle hook.


# 7 . Props Drilling (Context api).

# 8. What is axios?
Axios is an HTTP client library that allows you to make requests to a given endpoint.  
This could be an external API or your own backend Node.js server, for example.  
By making a request, you expect your API to perform an operation according to the request you made.

For example, if you make a GET request, you expect to get back data to display in your application.

Here are **5 reasons** why you should use Axios as your client to make HTTP requests:
- It has good defaults to work with JSON data. Unlike alternatives such as the Fetch API, you often don't need to set your headers. Or perform tedious tasks like converting your request body to a JSON string.
- Axios has function names that match any HTTP methods. To perform a GET request, you use the .get() method.
- Axios does more with less code. Unlike the Fetch API, you only need one .then() callback to access your requested JSON data.
- Axios has better error handling. Axios throws 400 and 500 range errors for you. Unlike the Fetch API, where you have to check the status code and throw the error yourself.
- Axios can be used on the server as well as the client. If you are writing a Node.js application, be aware that Axios can also be used in an environment separate from the browser.


