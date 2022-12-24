## 1. Why use Functional component not Class component?
- Understanding this keyword in class component is very different than other language.
- Remember to bind event handlers.
- Classes don't minify very well and make hot reloading very unreliable.
- Hooks helps us to allowing us stateful logic without tempering the component structure.

## 2. What is event.target.value in React exactly ?
Ans -   
* [event.target](https://stackoverflow.com/questions/67014481/what-is-event-target-value-in-react-exactly) gives you the element that triggered the event. So, **event.target.value** retrieves the value of that element (an input field, in my example).

* In React, events are [SynthenticEvent](https://reactjs.org/docs/events.html), a wrapper around the browser’s native event.
* It has the same interface as the browser’s native event, including stopPropagation() and preventDefault(), except the events work identically across all browsers.

## 3. What is forwardRef in React ?
Ans -
* The [forwardRef](https://stackoverflow.com/questions/66664209/how-can-i-use-forwardref-in-react) api, (coupled with the useImperativeHandle hook) lets you customize how and where your refs are placed inside your custom components. Also, forwardRef is the only way to pass a ref to your custom function components.

*  Refs can't be passed to function components, because They don't have instances! The only way to pass a ref to a function component is using forwardRef. When using forwardRef, you can simply pass the ref to a DOM element, so the parent can access it, or you could create an object with fields and methods using the useImperativeHandle hook.

## 4. Lifecycle method of React.
### **Mounting :**
Each component in React has a lifecycle which you can monitor and manipulate during its three main phases.
The three phases are: **Mounting, Updating, and Unmounting**.

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

## 5. React Hooks.
Hooks are the feature which allow you to use React features without having to write a class.
### Use Effect -
In class components, we have lifecycle methods to perform actions in a specific lifecycle stage of our component. For us to do something similar and perform side effects in our functional components, the React team created the useEffect Hook.

The useEffect Hook is called after every render of our component.

## 6. Props Drilling (Context api).

## 7. What is axios?
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


