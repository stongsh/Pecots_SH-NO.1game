# Pecots_SH-NO.1game
这是大学生第一次做的游戏  
关于src文件里的源文件首先我们需要去下载个[VisualStudioSetup](https://visualstudio.microsoft.com)
打开VS后我们安装一个**Visual Studio community**版本 将使用**C++的桌面开发**勾选将**Visual Studio扩展开发**勾选记得一定要创建三个文件夹分别存放tools vs环境 VS缓存  
在下载期间我们去[GLEW](https://glew.sourceforge.net/)和[GLFW](https://www.glfw.org/)下载**glew**和**glfw**是我们的运行环境
在glfw左上角中有一个名为**Download**的选项点击进去找到**Windows pre-compiled binaries**选择自己对应vs的平台设置我使用的是64bit的版本  
然后在glew中的**News**里选择最新的下载进去后下载**glew32.zip**
当我们VS下载安装好之后我们启动创建新项目**所选语言选择c++** **所有平台选择windows** **点击空项目** 点击下一步项目名自己取选择合适的位置点击创建  
将src中的代码拖到源文件里然后你会发现基本被标红了那是因为我们没有配置环境  
右键你的项目名点击**在文件资源管理器中打开**打开之后在此界面中创建一个**packages**文件夹并在其中创建**GLFW**文件夹  
将刚刚下载的glfw-?.?.bin.WIN??zip中的include和lib-vc2022解压到该文件夹下  
返回到packages文件夹中创建**GLEW**文件夹将**glew-?.?.?-win32.zip**中的**lib**和**include**放入glew文件夹中  
再将其中bin的文件放入**C:\Windows\System32**与**C:\Windows\SysWOW64**  
再次进入VS中右键**项目名**点击**属性**点击**VC++目录**点击**包含目录的小三角**点击**编辑**点击**新行**就是那个文件夹图标的然后点击**选择目录**就是三个点  
将**GLFW**中的**include**选择再重复将**GLEW**中的**include**选择  
然后我们双击**链接器**点击**常规**点击**附加目录库的小三角**点击**编辑****新行**然后点击**选择目录**  
将**GLFW**中的**lib-vc2022**选择将**GLEW**中的**lib\Release**中的**WIN32**或者**x64**选择PS:取决于你vs的平台设置x86选择WIN32  
然后我们在**连接器里**点击**输入的小三角**点击**编辑**将**OpenGL32.lib** **glfw3.lib** **glew32.lib**加入每个都要空一行然后点击**应用**就可以运行代码了
代码|说明
-|-|
execution_character_set("***")|此函数用于指出使用该程序时的字符集将***替换成想要的字符集
-|-|
GLFWwindow|这是GLFW自带的结构体用来定义窗口使用里面分别有 宽 高 标题 剩下的两项主播还没搞懂
-|-|
glClearColor(**f,**f,**f,**f)|这是Opengl用于设置替代原来颜色缓冲区的值的函数里面的**f分别为(r,g,b,a)最大值为1.0主播觉得1.0代表255
-|-|
glClear()|这是Opengl用于清除原来的颜色缓冲区括号中选择自己要以什么来代替该颜色缓冲区
-|-|
GL_COLOR_BUFFER_BIT|当前为颜色写入启用的缓冲区。这是微软的定义我个人理解为我们上面glClearColor所设置的颜色
-|-|
glfwInit()|该函数用于初始化GLFW库如果初始化失败则返回flase如果成功了则返回ture我们可以用此判断是否初始化成功
