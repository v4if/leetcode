## 内存泄漏如何检测，如何解决
[C++内存泄漏的几种情况](http://www.cnblogs.com/SeekHit/p/6549940.html)

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