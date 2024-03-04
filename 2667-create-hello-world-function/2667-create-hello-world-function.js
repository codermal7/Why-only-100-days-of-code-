/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    // return function(...args) {
    //     const name="Hello World";
    //     return name;
    // }
    return () => "Hello World";
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */