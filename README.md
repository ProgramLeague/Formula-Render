Formula-Render
===========
This project builds a tool to Parse and Rendering of Formula Code.

Design thinking
---------------
Class `Form` store the contents of each formula unit. Formula unit can be divided into different types. Such as general formula(`formual`), similar root sign formula(`sqrtForm`), similar summation formula(`inteForm`), similar matrix formula(`fracForm`) and other forms. They are all subclasses of formula base classes(`baseForm`). By combining the subscript and superscript member variables (`maker` type) of the formula class, a tree data structure is obtained(The two nodes are connected by the `maker` object).

As long as get the position of each formula unit, a complete formula can be drawn. Because of the tree structure, the top-down traversal method can be used. Calculate the position of the child node by combining the position of the parent node with the formula type. In this way, the position of each unit can be calculated layer by layer. And then we can render the formula.
