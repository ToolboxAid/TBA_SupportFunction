# Memory usage (ensure you are freeing allocated memory)

![This is an image](./assets/ToolboxAid.png)

## Libraries required (tag links)

- None

## Sample output

```c++
========================================
========================================
========================================
Loop cnt: 6

(-) negative number indicates memory allocated
(+) positive number indicates memory delete/free

----------------------------------------

Pre allocate usage S/B  0 byte difference

HEAP Size    : 355.293 KB diff:   0 B
HEAP Free    : 330.973 KB diff:   0 B
HEAP Min Free: 293.535 KB diff:   0 B
HEAP Max Allo: 117.988 KB diff:   0 B

----------------------------------------
Post allocated usage
RandomMemoryPig(construtor)

HEAP Size    : 355.262 KB diff: -32 B
HEAP Free    : 324.336 KB diff: -6.637 KB
HEAP Min Free: 293.535 KB diff:   0 B
HEAP Max Allo: 117.988 KB diff:   0 B

Memory allocate size: 6748
Human readable size : 6.590 KB

----------------------------------------
Post free/delete memory usage, s/b positive of allocated usage
~RandomMemoryPig(destructor)

HEAP Size    : 355.293 KB diff:  32 B
HEAP Free    : 330.973 KB diff: 6.637 KB
HEAP Min Free: 293.535 KB diff:   0 B
HEAP Max Allo: 117.988 KB diff:   0 B
```
