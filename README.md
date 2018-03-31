# leetcode

## leetcode exercises,algorithms part!

### TwoSum:

```
1.key point: unorderd_map(16ms), map(24ms)
2.大概是前50%的样子，并不知道如何进一步提升性能
```

### addTwoNums:

```
1.新建ListNode对象的时候没有分配存储空间导致bus error
2.原题设计上null pointer使用了NULL而不是nullptr
3.考虑将测试用例变成用户输入
4.考虑将在不同对象上的相同操作提炼为子函数
5.c++链表操作复习
```

### Longest Substring Without Repeating Characters:

```
1.map内部根据键值红黑树排序，一开始以为根据插入时间排序导致错误
2.情况分为最长子串在字符串开头，中间，以及结尾，需要用不同的方式进行处理
3.tag中hash table没有用到，可能是提高效率的关键点？（不过感觉不是
4.代码还是不够优雅（嘤
```

### String to Integer (atoi):

```
1.没有考虑到很多很多情况，比如溢出，字符串不是单纯的数字串，数字和字母结合的字符串需要截取前面部分的数字进行转换而不是单纯返回0，空格etc
2.遇到了segmentation fault，先定位再调试（。
3.一开始性能不佳，通过把一些判断移出循环是性能到达了平均水平
```

### Binary Tree Inorder Traversal:

```
1.使用了递归算法，因为非递归并没有想出来（垢
2.传参数方面出了一点问题
```

### Unique Binary Search Trees:

```
1.可以用递归的思想，不同根结点情况下叶结点组合情况可由之前计算所得的叶结点数计算得出
2.使用数组方式存储途经所有结果是为了避免重复计算，在两边相同结点数的处理方法上优点不优雅（。
```

### Same Tree:

```
1.没有什么难度
```

### Symmetric Tree:

```
1.同上
```

### Binary Tree Level Order Traversal:

```
1.可以通过保留两个queue来提高效率
2.实现的时候其实可以不在循环中声明将要push到vector中的vector，因为不是push进指针，所以下一次对同一个vector对象的改写其实不会影响到已经在别的vector中的前一次push进的vector（我的表述能力。。。。
```

### Binary Tree Level Order Traversal II:

```
1.初版用了stack存放原本的顺序level排序
2.会再版提高性能
```

### Balanced Binary Tree:

```
1.初版使用了map，性能不佳，换成unordered_map以后有些许提升
2.第二版直接递归算法，性能有比较大的提升，如果吧每个叶结点看成深度为2，即node为null的时候返回深度为1时，性能还会有所提升，这时候因为0可以代表bool中的false原函数返回值也可以变为返回depth(root)
```

### Minimum Depth of Binary Tree:

```
1.使用了深度优先算法，没什么好说的
2.关于提高性能，看到一个答案想法很好，使用level遍历的方式，找到第一个叶结点返回已经遍历的层数
```

### Maximum Depth of Binary Tree:

```
1.没什么难度
```

### Binary Tree Zigzag Level Order Traversal:

```
1.使用deque方便操作
2.注意不能在循环中使用nodeQ.size()，因为nodeq的push操作改变了队伍的size，会产生segmentation fault
```

### Invert Binary Tree:

```
1.没有难度
```

### Binary Search Tree Iterator:

```
1.用一个栈作为成员变量，初始化时存入当前序列的node次序，每次pop出最小的值即可
```

### Flatten Binary Tree to Linked List:

```
1.没什么难度 注意不要出现segmentation fault就好～
```

### Construct Binary Tree from Preorder and Inorder Traversal:

```
1.使用递归根据前序遍历找出每个子树根节点，和中序遍历结合将数值分成左右子树两部分并进行递归。
2.有性能更加好的解法，还没看
```

#### Convert Sorted Array to Binary Search Tree:

```
1.无难度
```

### Binary Tree Right Side View:

```
1.使用level遍历的方式，否则会忽略不相邻两棵树右边的树高度较小的情况。
```

### Binary Tree Preorder Traversal

```
1.没有难度
```

### searchMatrix

```
1.使用两个二分法查找，注意临界值的判断，防止bus error 或者segmentation fault就好
```

### Remove Duplicates from Sorted Array

```
一开始使用了vector.erase(), 由于erase内部实现是当删除一个元素时将后面的元素往前移一格，效率很低。
然后使用了两个指针，将不重复的元素移到前k位，效率较高
```

### 3Sum

```
1.sort
2.确定第一个数
3.在余下的list中找两个数加起来等于-第一个数
4.为了防止重复，每次找到正确答案时将指针移到不重复的数上
```

