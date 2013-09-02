bf - A Collection of Brainf*ck Implementations
==============================================

##JavaScript Interpreter

```bf.js``` is a simple JavaScript Brainf*ck interpreter.

```js
var core = new Bf();
var output = core.parse('++++++++++[>+++++++>++++++++++>+++>+<<<<-'
                        + ']>++.>+.+++++++..+++.>++.<<+++++++++++++++'
                        + '.>.+++.------.--------.>+.>.');
console.log(output);

/* OUTPUT:
 *    Hello World!
 *
 */
```



