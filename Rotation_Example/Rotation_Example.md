# Parallelizing Computation: Rotation Example
Written by [Matt Bovyn](https://github.com/mbovyn)

In this example, we'll walk through a bit of computation that I had to do as part of my research. Hopefully along the way we'll demonstrate:
* Writing, compiling and running C code
* Using Mathematica to get a handle on unfamiliar math
* A little trick I came up with to get Mathematica to write C code for us
* Using the HPC to get a lot of computation done quickly

<a name="intro"></a>
## Problem Statement and Plan of Attack

### The Problem We Want To Solve

Let's say we have a sphere which rotates about its center. It is subjected to some rotations, and we want to be able to see its state at some point later in time. For example, let's say the rotations have normally distributed random magnitudes and all axes of rotation are equally likely. We can generate such random rotations by taking three numbers from a normal distribution and assigning them to the magnitude of the rotation of the sphere about the x, y and z axes.

### Solution

We can write some code which generates many random rotations as described. Once we have the rotations, we can apply them to a set of points which represent the sphere to see what trajectories they take (you could make a video of the sphere ).

However, this represents a bit of an issue: it turns out you can't add rotations in the form we're generating them (x,y,z). So, to find out where a point goes, you need to output every rotation you generate and apply them one by one (then do it again for each of the points that make up the sphere). If you generate, say, millions of rotations for a single stochastic trajectory, things get out of hand pretty quickly!

However, there is some math that can save us: quaternions. Quaternions are something like complex numbers, but have 4 components instead of two. They are used to keep track of rotations in things like video game engines. Rotations represented as quaternions can be "added", so we can output a single number from our simulation that gives us the state of the sphere at the end of the simulation.

### Implementation

So we can simulate quickly, we'll write C code to generate the random rotations, convert them into quaternions and compose them ("add" them up). However, the math to do the conversion and add the quaternions is at best tedious to write out into C code. Its also not simple to figure out in the first place.

To generate the correct functions, we'll use Mathematica. Then we'll use a handy trick I came up with to turn functions generated in Mathematica into C code.

Finally, we'll compile this C code and run many copies of it on the HPC at once. In this way we can gather statistics on the average behavior of the spheres.

<a name="C"></a>
## C Code for Generating Rotations

C code which generates the rotations is included in [rotation_example.c](rotation_example.c). A look through it will motivate what we need to figure out how to do with Mathematica.

After including files and defining the necessary variables and including files, the C code has a single for loop. Inside, it generates three random numbers, `v[0]`, `v[1]`, and `v[2]`. Then it calls `compose_rotations()`, which it claims converts the random numbers into a quaternion and composes the rotation with the previous one. This is what we'll have to get Mathematica to write for us! The rest of the file deals with random number generation and output.

<a name="Mathematica"></a>
## Mathematica Notebook on Quaternion Math
