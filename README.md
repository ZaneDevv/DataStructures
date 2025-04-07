# Data Structures

I have been wondering how all data structures work inside, so I decided to make my own library and deal with them by myself.
As a method to study it, I will expain here each one of them.

It is important to highlight the fact that this library has no the intention to be used in serious projects, it has only the goal of learning.
That is being said that, let's start explaining each one of them.

# Array

This data structure is the easiest one. You just reserve a block of bytes in memory and don't use it at all, so we can assign the values we want here.<br>
For instance, let's imagine we need to reserve bytes enough to save n amount of m bytes.<br>

In each block of bytes, we can set any data we want, defining the value of m here due to for each data type, we will need more or less bytes.<br>
Thefore, the amount of bytes we need is defined by the next formula: `total_bytes = sizeof(data_type) * number_of_elements`<br>

It makes that getting the data saved in each block is extremely fast because with a simple and intuitive formula, we can get the value in any block.<br>

# Vector

As you might notice, we cannot change easily how many things we want to save in the array, so it will be important to create another data structure whose size changes dinamically depending of the amount of data we are saving in the structure.<br>
This data structure has a name that can change a bit. For instance, in `C#` it is named as `List` instead of `Vector`.<br>
To create this data structure, each time we want to add something, we need to check if we run out of space. If it is the case, we will seak for a new space in memory to allocate all the data, copy the data to this new space and then, remove the old space allocated.<br>
This is quite more hard to compute than the array due to the process we need to do each time we need more space, but getting any data in here is as easy as the array due to the fact that we can keep using the same formula.<br>

# Linked List

This data structure changes the logic to avoid running out of space. Each time we add a new data in the structure, we create a `node` with the next information:

<ul>
	<li> The previous node. </li>
	<li> The next node. </li>
	<li> The data this node is saving. </li>
</ul>

This is quite harder to compute because each time we need to get the nth value in here, we need to go over all the previous nodes until we get what we wanted.<br>

# Stack

Stacks are quite simple and when we are programming, the memory we are using by making variables and functions is saved in stacks most of the time. Let's break it down:<br>
Let's imagin a stack of plates for instance, we you add a new plate, you add it on the first plate and this new plate turns into the new first plate and, when we remove a plate, we remove the first plate tunring the second plate into the new first plate.<br>
This behaviour is exactly what we are doing here: when we save data in a stack, each time we add a new one we add it in the first position and, each time we remove data in the stack, we also remove the first one.<br>

# Queue

Queues, just like stacks, have a nice and intuitive interpretation to understand how they work.<br>
Imagine a line (or queue) in a supermarket. When someone joins to this line, that person is in the last position of the line and, we someone gets out of the line, that person was the first one in the line.<br>
That is how queues work with data: when we add something new to a queue, it will be in the last position; when we remove something from out queue, that thing was in the first position.<br>

# Set

In this case, sets follow the same rules as sets in mathematics: there cannot be repeated values. Each time you add something to a set, it might not be added if that values was alerady on the set.<br>
Sometimes we also add some functions to work with this data structure as if it was a set in mathematics using the union `(A∪B)` and intersection `(A∩B)` operations.
