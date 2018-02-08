## 内存泄漏如何检测，如何解决
[C++内存泄漏的几种情况](http://www.cnblogs.com/SeekHit/p/6549940.html)
[C/C++内存泄漏及检测](https://www.cnblogs.com/skynet/archive/2011/02/20/1959162.html)

## 系统调用

## UDP和TCP的区别

## 数据库优化

## tcp三次握手四次挥手，TCP 拥塞控制等

## 各种排序算法的时间复杂度和稳定性

## [硬链接与软链接](https://www.ibm.com/developerworks/cn/linux/l-cn-hardandsymb-links/)

## [阿里杭州站C++研发面经](http://www.zheyibu.com/article/4836.html)

## [阿里实习生C/C++研发内推三面+专场三面](https://www.nowcoder.com/discuss/5773)

## RVO/NRVO(named return value optimation) 当局部临时对象被构造的时候，直接被构造在将要拷贝/移动到的对象上，省去了拷贝和移动构造

## 线程同步：互斥锁、条件变量、信号量

## 进程通信：管道、消息队列、共享内存、信号、套接字

## 红黑树
但它是如何保证一棵n个结点的红黑树的高度始终保持在logn的呢？这就引出了红黑树的5个性质：
* 每个结点要么是红的要么是黑的。  
* 根结点是黑的。  
* 每个叶结点（叶结点即指树尾端NIL指针或NULL结点）都是黑的。  
* 如果一个结点是红的，那么它的两个儿子都是黑的。  
* 对于任意结点而言，其到叶结点树尾端NIL指针的每条路径都包含相同数目的黑结点。 

[wiki_红黑树](https://zh.wikipedia.org/wiki/%E7%BA%A2%E9%BB%91%E6%A0%91)

[wiki_二叉搜索树](https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%85%83%E6%90%9C%E5%B0%8B%E6%A8%B9)

[wiki_AVL树](https://zh.wikipedia.org/wiki/AVL%E6%A0%91)

BST删除结点：叶子结点；左子树空或者右子树空；左右都非空，左最大或右最小代替当前结点

红黑树相对于AVL树的删除效率较高，AVL删除结点的算法可以参见BST的删除结点，但是删除之后必须检查从删除结点开始到根结点路径上的所有结点的平衡因子。因此删除的代价稍微要大一些。每一次删除操作最多需要O(logN)次旋转。因此，删除操作的时间复杂度为O(logN)+O(logN)=O(2logN)；而红黑树删除一个结点最多只需要3次旋转操作。

两者的查找代价都在O(logN)，AVL树每一次插入数据使得AVL中某些结点的平衡因子，左子树减去右子树的高度差，超过1就必须进行旋转操作，最多进行两次旋转；红黑树插入结点时，需要旋转操作和变色操作，最多只需要2次旋转，这一点和AVL的插入操作一样。虽然变色操作需要O(logN)，但是变色操作十分简单，代价很小。

对于在内存中的查找结构而言，红黑树的效率已经非常好了。但是如果是数据量非常大的查找呢？将这些数据全部放入内存组织成红黑树结构显然是不实际的。实际上，像OS中的文件目录存储，数据库中的文件索引结构的存储.... 都不可能在内存中建立查找结构。必须在磁盘中建立好这个结构。
在磁盘中组织查找结构，从任何一个结点指向其他结点都有可能读取一次磁盘数据，再将数据写入内存进行比较。大家都知道，频繁的磁盘IO操作，效率是很低下的(机械运动比电子运动要慢不知道多少)。显而易见，所有的二叉树的查找结构在磁盘中都是低效的。因此，B树很好的解决了这一个问题。

通常的说法是：内存访问速度是纳秒级(24-93ns)，磁盘的访问速度是毫秒级(13.0ms)，SSD的速度是微妙级别(30-300us)

`B树`
![xx](http://img.my.csdn.net/uploads/201106/7/8394323_13074405906V6Q.jpg)
`B+树`
![xx](http://www.niceru.com/wp-content/uploads/2013/09/2.png)

[二叉查找树，红黑树，AVL树，B~/B+树(B-tree)，伸展树——优缺点及比较](http://blog.csdn.net/bytxl/article/details/40920165)

[理解B+树算法和Innodb索引](http://www.niceru.com/topic/420.html)

## 产生死锁的四个必要条件？
* 互斥条件：进程对所分配到的资源不允许其他进程进行访问，若其他进程访问该资源，只能等待，直至占有该资源的进程使用完成后释放该资源
* 请求和保持条件：进程获得一定的资源之后，又对其他资源发出请求，但是该资源可能被其他进程占有，此事请求阻塞，但又对自己获得的资源保持不放
* 不可剥夺条件：是指进程已获得的资源，在未完成使用之前，不可被剥夺，只能在使用完后自己释放
* 环路等待条件：是指进程发生死锁后，必然存在一个进程--资源之间的环形链

## 处理死锁的基本方法
* 预防死锁：通过设置一些限制条件，去破坏产生死锁的必要条件
* 避免死锁：在资源分配过程中，使用某种方法避免系统进入不安全的状态，从而避免发生死锁
* 检测死锁：允许死锁的发生，但是通过系统的检测之后，采取一些措施，将死锁清除掉
* 解除死锁：该方法与检测死锁配合使用


## m阶B树
* 根结点至少有两个子女；
* 每个非根节点所包含的关键字个数 j 满足：┌m/2┐ - 1 <= j <= m - 1；
* 除根结点以外的所有结点（不包括叶子结点）的度数正好是关键字总数加1，故内部子树个数 k 满足：┌m/2┐ <= k <= m ；
* 所有的叶子结点都位于同一层。

在B-树中，每个结点中关键字从小到大排列，并且当该结点的孩子是非叶子结点时，该k-1个关键字正好是k个孩子包含的关键字的值域的分划。
因为叶子结点不包含关键字，所以可以把叶子结点看成在树里实际上并不存在外部结点，指向这些外部结点的指针为空，叶子结点的数目正好等于树中所包含的关键字总个数加1。

B-树中的一个包含n个关键字，n+1个指针的结点的一般形式为： （n,P0,K1,P1,K2,P2,…,Kn,Pn）
其中，Ki为关键字，K1<K2<…<Kn, Pi 是指向包括Ki到Ki+1之间的关键字的子树的指针。

## hashmap.hashtable 区别，怎样设计实现一个高效的线程安全的hashmap 

## 给定a、b两个文件，各存放50亿个url，每个url各占用64字节，内存限制是4G，如何找出a、b文件共同的url？
可以估计每个文件的大小为5G*64=300G，远大于4G。所以不可能将其完全加载到内存中处理。考虑采取分而治之的方法。 遍历文件a，对每个url求取hash(url)%1000，然后根据所得值将url分别存储到1000个小文件（设为a0,a1,...a999）当中。这样每个小文件的大小约为300M。遍历文件b，采取和a相同的方法将url分别存储到1000个小文件(b0,b1....b999)中。这样处理后，所有可能相同的url都在对应的小文件(a0 vs b0, a1 vs b1....a999 vs b999)当中，不对应的小文件（比如a0 vs b99）不可能有相同的url。然后我们只要求出1000对小文件中相同的url即可。 比如对于a0 vs b0，我们可以遍历a0，将其中的url存储到hash_map当中。然后遍历b0，如果url在hash_map中，则说明此url在a和b中同时存在，保存到文件中即可。 如果分成的小文件不均匀，导致有些小文件太大（比如大于2G），可以考虑将这些太大的小文件再按类似的方法分成小小文件即可。

## 根据每个订单的商品做hash, 分成小文件 做统计,   再用堆排序取top100

## 从很长的数据流等概率随机采样
[蓄水池抽样](http://blog.csdn.net/yangliuy/article/details/43924581)
```python
import random  
SAMPLE_COUNT = 10  
   
# Force the value of the seed so the results are repeatable  
random.seed(12345)  
   
sample_titles = []  
for index, line in enumerate(open("enwiki-20091103-all-titles-in-ns0")):  
        # Generate the reservoir  
        if index < SAMPLE_COUNT:  
                sample_titles.append(line)  
        else:  
                # Randomly replace elements in the reservoir  
                # with a decreasing probability.  
                # Choose an integer between 0 and index (inclusive)  
                r = random.randint(0, index)  
                if r < SAMPLE_COUNT:  
                        sample_titles[r] = line  
print sample_titles  
```

## shuffle
这里的方法是在每次迭代时交换这个被取出的数字到原始列表的最后

```bash
-- To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 downto 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]
```

## shell脚本抽取制定字符串、grep+awk+cut+sed
[shell脚本抽取制定字符串、grep+awk+cut+sed](http://blog.csdn.net/zhangfn2011/article/details/39890875)

## 读写锁
[实现线程读写锁的四种方法](http://blog.csdn.net/ojshilu/article/details/25244389)

## 自旋锁
[自旋锁代替互斥锁的实践](http://ifeve.com/practice-of-using-spinlock-instead-of-mutex/)

## 52张扑克牌，红桃A和黑桃A同时被一个人拿到的概率
[52张扑克牌，红桃A和黑桃A同时被一个人拿到的概率](http://blog.csdn.net/huntinux/article/details/16844941)

## 面经
[面试题干货在此 ](https://www.nowcoder.com/discuss/57978?type=0&order=0&pos=24&page=1)

## select poll epoll
![xx](http://img.blog.csdn.net/20160422143642896)

## 同步与异步 阻塞与非阻塞
同步和异步关注的是消息通信机制 (synchronous communication/ asynchronous communication)

所谓同步，就是在发出一个`调用`时，在没有得到结果之前，该`调用`就不返回。但是一旦调用返回，就得到返回值了。换句话说，就是由`调用者`主动等待这个`调用`的结果。而异步则是相反，`调用`在发出之后，这个调用就直接返回了，所以没有返回结果。换句话说，当一个异步过程调用发出后，调用者不会立刻得到结果。而是在`调用`发出后，`被调用者`通过状态、通知来通知调用者，或通过回调函数处理这个调用。

阻塞和非阻塞关注的是程序在等待调用结果（消息，返回值）时的状态

阻塞调用是指调用结果返回之前，当前线程会被挂起。调用线程只有在得到结果之后才会返回。
非阻塞调用指在不能立刻得到结果之前，该调用不会阻塞当前线程。

![xx](http://static.zybuluo.com/zhenlanghuo/aal4brj3okthdticuenp4vco/5%E7%A7%8DIO%E6%A8%A1%E5%9E%8B%E6%AF%94%E8%BE%83.png)

在处理 IO 的时候，阻塞和非阻塞都是同步 IO。只有使用了特殊的 API 才是异步 IO。
![xx](https://pic4.zhimg.com/80/7d3eb389b7724878bd7e12ebc6dbcdb5_hd.jpg)

[并发模型](https://github.com/linw7/TKeed/blob/master/%E5%B9%B6%E5%8F%91%E6%A8%A1%E5%9E%8B.md)
