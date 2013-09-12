bf - A Collection of Brainf*ck Implementations
==============================================

##Brainf*ck compiler

```bf.c``` contains the source code for the ```bfc``` compiler. It is written in C, and is compiled using GCC. You can grab a copy of the ```bfc``` executable and begin using it right away, but I'm sure you want to make it first.

###How to Build
In order to successfully make and run ```bfc``` you need to have ```gcc``` installed and usable.

```bash
git clone https://github.com/shrimpboyho/bf.get
cd bf
make
```

The makefile will build the ```bfc``` compiler and invoke it to compile a sample brainf*ck source file (```test.bf```) and turn it into the executable ```unittests```. It then runs ```unittests``` and displays this welcoming message if everything works fine.

```bash
Hello World!

```

###Compiler Flags

```bfc``` requires 2 arguments. The first must be a brainf*ck source file with the ```.bf``` extension. The second argument is the name of the executable you want produced. There is an optional ```-c``` flag, and if you include it as an optional third argument you will see a nifty little ```a.c``` file, which is basically the brainf*ck code converted to C.

##JavaScript Interpreter

```bf.js``` is a simple JavaScript Brainf*ck interpreter. It is not complete yet, for there is no support for byte input.

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



