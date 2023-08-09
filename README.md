# points-lottery
course design,you can use supermarket points to play luck draws
# 基本介绍
这个是我大二上学期的课程作业仓库，
目的是实现一个超市积分抽奖系统，
基本的功能是实现一个能够在超市购物的同时进行抽奖的积分系统，
主要用到的技术栈就是Qt和c++，
这个项目是由我和我的组员协作完成的，

[wang-pine](https://github.com/wang-pine)

[none102](https://github.com/none102)

[luoningliu](https://github.com/luoningliu)

> 叠甲：由于开发这个项目的时候我们才刚刚学数据结构，仅仅学过简单的c++开发，Qt还是我们暑假自己摸索的，所以项目中可能有不成熟的地方，或者是没有使用高级的算法或数据结构而是选择了简单的for循环等等，请注意，那绝非我们刻意而为之，只是真的当时太菜了，希望各路大神以发展的眼光看问题，轻点喷啊，thank you
# 基本架构图
![超市购物积分抽奖系统Vol 2](https://github.com/wang-pine/points-lottery/assets/88295502/3f474c93-5dd6-40e1-9a7e-33788e877204)
![项目架构](https://github.com/wang-pine/points-lottery/assets/88295502/8bf85980-a21d-473b-8048-d9143dc98abc)
当然了，项目开发后期由于Qt独特的文件结构问题，我没有完全的按照架构开发，这个可以作为开发的思路

# 基本函数以及功能实现
## 1.登录
登录函数：用于用户进行登录和注册操作。用户启动程序可以选择通过输入用户名密码进行登录或者进行注册操作。若选择通过输入用户名密码进行登录，
系统会自动将用户所输入的用户名和密码与文件中所存储的用户名和密码进行校验。若校验失败，则弹出登录失败提醒；若校验成功，
则根据用户的身份分别进入“顾客”界面和“管理员”界面。若选择注册操作，则可在登录页面输入用户名和密码进行注册操作
如图所示
![image](https://github.com/wang-pine/points-lottery/assets/88295502/d3bc0523-3626-4d6b-9afb-78ac8e83841d)
## 2.抽奖算法
这一部分是组员[none102](https://github.com/none102)设计的，感谢
用于进行抽奖操作，返回抽奖所得到的奖品。系统调用抽奖算法，生成一个长度为1000的数组。
同时，系统通过识别当前抽奖的概率将一定数量的数组成员赋值为奖品的ID,并通过生成随机数从而达到抽奖目的
如图所示
![image](https://github.com/wang-pine/points-lottery/assets/88295502/472b22e4-a3ae-4b8b-b97d-4d0063ba06ba)
## 3.修改信息
管理员在页面中点击“查看”按钮后查看当前的用户信息情况，并且可以通过选中相应的信息直接在该页面进行修改。
点击“保存”按钮之后，系统自动在文件之中保存修改后的信息，如图所示。

![image](https://github.com/wang-pine/points-lottery/assets/88295502/bef4760f-8168-4c22-8efc-c74937e9be03)

# 基本界面信息
![image](https://github.com/wang-pine/points-lottery/assets/88295502/e898979b-420b-4146-aafd-8b870984e710)
登录页面

![image](https://github.com/wang-pine/points-lottery/assets/88295502/bcd63578-c972-4bc6-bad4-4fc611ed697e)
注册页面

![image](https://github.com/wang-pine/points-lottery/assets/88295502/1bf12531-9b3c-464b-86bd-701d07b7f111)
输入页面

![image](https://github.com/wang-pine/points-lottery/assets/88295502/3dc0f337-a4e0-48c1-9490-262316991d2e)
注册成功

![image](https://github.com/wang-pine/points-lottery/assets/88295502/10f643fc-9b7b-4e6c-a99f-5b6b7bd4302c)
主界面

![image](https://github.com/wang-pine/points-lottery/assets/88295502/84546bcc-8bac-4191-933a-46e54123f0f3)
抽奖页

![image](https://github.com/wang-pine/points-lottery/assets/88295502/14b02471-5f44-48ff-a50b-043fc0c7397d)
报错页

![image](https://github.com/wang-pine/points-lottery/assets/88295502/5eab9f4d-826f-4655-99aa-0c02d497cca5)
充值后进行抽奖

![image](https://github.com/wang-pine/points-lottery/assets/88295502/5733a9a7-49c1-401a-b5d7-c264b96b6d1d)
管理员页面

![image](https://github.com/wang-pine/points-lottery/assets/88295502/6447318d-5bb0-412b-8796-1b6c0cb68579)
能自动生成id

![image](https://github.com/wang-pine/points-lottery/assets/88295502/c5b5733e-6b2e-4971-b194-8fdc912d6e05)
系统保存主要用户的特征值

![image](https://github.com/wang-pine/points-lottery/assets/88295502/8c63f011-8ec4-49b5-8fed-3e62301decf5)
查找用户信息

![image](https://github.com/wang-pine/points-lottery/assets/88295502/c9c8c20f-3c79-4fed-a200-125fae0153a3)
修改用户信息

![image](https://github.com/wang-pine/points-lottery/assets/88295502/75e1cb69-e8df-4ee6-9cda-1d22cdc485da)
修改商品信息

![image](https://github.com/wang-pine/points-lottery/assets/88295502/462c73e4-9340-4d89-9d7a-44181dca7ba6)
修改奖品

![image](https://github.com/wang-pine/points-lottery/assets/88295502/16a2314f-5ce0-4af6-ad6d-1cbd4d2dc641)
更改奖池

![image](https://github.com/wang-pine/points-lottery/assets/88295502/1d3f23ae-a880-4560-8382-5d35fb09a237)
购买页面

# 项目的不足与收获
时间仓促（准确来说是两周左右），开发遇到了各种各样的问题，最后我们选用了比较省事的方法，很多东西都没有优化（包括但不仅限于我们没有封装很成熟的函数，
因为时间太仓促，没有考虑完备函数封装的问题），可能会显得较为臃肿，但是放心，由于比较草率，可读性还是不错的🤣

release里面有一个压缩包，里面封装了编译之后的exe程序以及Qt所需要的依赖，可以跑一跑玩一玩，觉得不错可以点一个star，如果喜欢的话也欢迎提issue
，提pr，如果我有时间的话一定会对程序进行优化的😊
