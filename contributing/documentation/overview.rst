参与贡献文档
=================================
译者：`SHANG Guokan`_

.. _SHANG Guokan: https://github.com/shangguokan


Symfony项目的一个至关重要的理念是： **文档与代码同等重要**。
这也是为什么需要投入精力用于文档化新的特性，
以及保持其余文档处于最新的状态。

世界上有超过700位开发者都参与贡献了Symfony文档，
并且我们非常高兴你打算加入我们这个社区。
这篇指南将为你解释所有在参与贡献Symfony文档过程中必要的知识。

在首次贡献之前
------------------------------

**在开始贡献前**，你应该首先了解：

* Symfony文档采用 reStructuredText_ 标记语言书写。
  如果你不熟悉这种格式，请阅读 :doc:`这篇文章 </contributing/documentation/format>`
  来快速了解它的特征。
* Symfony文档托管在 GitHub_ 上。 你需要一个Github账户来参与贡献文档。
* Symfony文档遵循
  :doc:`Creative Commons BY-SA 3.0 协议 </contributing/documentation/license>`
  并且你的所有贡献也都将默认跟随此协议。

首次文档贡献
-------------------------------------

在本小节中，你将学习怎样首次参与文档贡献。下一节将介绍每次你参与文档贡献的操作流程。

现在假设你想要改善《Symfony圣经》中《安装》这一章节。为了实现更改，跟随如下几步：

**Step 1.** 访问Symfony官方文档库地址
`github.com/symfony/symfony-docs`_ 并且 `fork the repository`_ 到你的个人账号。
只需进行一次这样的操作.

**Step 2.** **Clone** 分支仓库到你的本地 （如下例子使用
``projects/symfony-docs/`` 目录来存储文档;
请修改<YOUR GITHUB USERNAME>）:

.. code-block:: bash

    $ cd projects/
    $ git clone git://github.com/<YOUR GITHUB USERNAME>/symfony-docs.git

**Step 3.** 在修改前，切换到 **最旧的维护分支** 。目前为 ``2.3`` 分支：
（译者注：此中文文档将一直跟随最新的版本，请忽略此条）

.. code-block:: bash

    $ cd symfony-docs/
    $ git checkout 2.3

如果你是要参与贡献最新特性的文档，请切换到最新的Symfony版本：``2.5``，``2.6``，等。

**Step 4.** 为你的修改创建一个专用的 **新分支**。
这将极大的简化你的修订与合并工作。可以采用一个简单好记的名字来命名你的新分支：

.. code-block:: bash

    $ git checkout -b improve_install_chapter

**Step 5.** 在文档中做些修改。添加、调整、改写，甚至删除现有的内容，
但请确保你遵守了文档标准
:doc:`/contributing/documentation/standards`.

**Step 6.** 将修改**Push**到forked库的improve_install_chapter分支:

.. code-block:: bash

    $ git commit book/installation.rst
    $ git push origin improve_install_chapter

**Step 7.** 现在就可以发起一个 **pull request** 了。
在你的forked库页面 ``https//github.com/<YOUR GITHUB USERNAME>/symfony-docs``，
在侧边栏点击 ``Pull Requests`` 链接。

然后点击 ``New pull request`` 按钮。由于Github不能明确的知道你要提交的修改，
所以需要你选择适当分支上的适当修改来进行提交：

.. image:: /images/contributing/docs-pull-request-change-base.png
:align: center

在此例中，**base repository** 应为 ``symfony/symfony-docs`` 并且 **base branch** 应为 ``2.3``
（修改基于此分支之上）。 **compare repository** 应为forked库，``symfony-docs``
并且 **compare branch** 应为 ``improve_install_chapter`` （你创建并修改后的分支）。

.. _pull-request-format:

**Step 8.** 最后一步是填写pull request的 **description** 。
为了确保你的提交能够被快速评估，
请把如下的表格添加在你pull request description的开头：

.. code-block:: text

    | Q             | A
    | ------------- | ---
    | Doc fix?      | [yes|no]
    | New docs?     | [yes|no] (PR # on symfony/symfony if applicable)
    | Applies to    | [Symfony version numbers this applies to]
    | Fixed tickets | [comma separated list of tickets fixed by the PR]

在上面的例子中，表格应为:

.. code-block:: text

    | Q             | A
    | ------------- | ---
    | Doc fix?      | yes
    | New docs?     | no
    | Applies to    | all
    | Fixed tickets | #10575

**Step 9.** 至此，你已经成功的提交了你的首次文档贡献，**恭喜**，
文档管理员将尽快评估你的工作，并且会让你知晓任何需要的改动。

如果在提交后你发现需要添加或修改，无需创建一个新的pull request。只需确保你在正确的分支，
修改并提交到此分支即可。

.. code-block:: bash

    $ cd projects/symfony-docs/
    $ git checkout improve_install_chapter

    # ... do your changes

    $ git push

**Step 10.** 在你的pull request最终被接受并合并到Symfony文档的主分支后，你将会加入到 `Symfony Documentation Contributors`_
名单中。此外，如果你加入 SensioLabsConnect_ ，你将得到 `Symfony Documentation Badge`_ 徽章。

第二次文档贡献
--------------------------------------

首次文档贡献花费了一些时间，因为你需要fork文档库，学习怎样书写文档，创建pull requests等。
第二次文档贡献将变得非常简单，但需要注意的是，Symfony的文档库在不断的变化中，
你Github账户中的分支于官方版本相比很有可能已经不是最新的了。

为了解决这个问题需要 `sync your fork`_ 进行库的同步.
只需执行这个指令来告诉git，你账户forked库的上游库（原库）：

.. code-block:: bash

    $ cd projects/symfony-docs/
    $ git remote add upstream https://github.com/symfony/symfony-docs.git

现在你可以 **进行同步** :

.. code-block:: bash

    $ cd projects/symfony-docs/
    $ git fetch upstream
    $ git checkout 2.3
    $ git merge upstream/2.3

这个指令将更新 ``2.3`` 分支（你用于创建新修改分支的源分支）。
如果你使用的是其他源分支，
比如 ``master``，将 ``2.3`` 替换成master即可.

接下来你就可以仿照上一节中的流程了：

.. code-block:: bash

    # 基于你的源分支2.3创建新分支my_changes来进行文档修改
    $ cd projects/symfony-docs/
    $ git checkout 2.3
    $ git checkout -b my_changes

    # ... 文档修改

    # 提交你的修改到本地并push到GitHub
    $ git add xxx.rst     # (optional) only if this is a new content
    $ git commit xxx.rst
    $ git push

    # 在GitHub上创建Pull Request
    #
    # 加入这个表格在description中:
    # | Q             | A
    # | ------------- | ---
    # | Doc fix?      | [yes|no]
    # | New docs?     | [yes|no] (PR # on symfony/symfony if applicable)
    # | Applies to    | [Symfony version numbers this applies to]
    # | Fixed tickets | [comma separated list of tickets fixed by the PR]

第二次文档贡献完成，**恭喜**，你也可以看看你在
`Symfony Documentation Contributors`_ 贡献列表中的排名。

下一次文档贡献
-------------------------------------

你已经完成了两次文档贡献，你或许已经发现git在此过程中发挥的神奇作用，这也是为什么你的下一次贡献将更加快速。
在这里你可以找到一个完整的文档贡献流程
**清单**:

.. code-block:: bash

    # 与上游库进行同步
    $ cd projects/symfony-docs/
    $ git fetch upstream
    $ git checkout 2.3
    $ git merge upstream/2.3

    # 创建新分支用于修改
    $ git checkout 2.3
    $ git checkout -b my_changes

    # ... 文档修改

    # add 并且 commit 你的修改
    $ git add xxx.rst     # (optional) only if this is a new content
    $ git commit xxx.rst
    $ git push

    # 在GitHub上创建 Pull Request
    #
    # 在description中加入这个表格：
    # | Q             | A
    # | ------------- | ---
    # | Doc fix?      | [yes|no]
    # | New docs?     | [yes|no] (PR # on symfony/symfony if applicable)
    # | Applies to    | [Symfony version numbers this applies to]
    # | Fixed tickets | [comma separated list of tickets fixed by the PR]

    # (可选) 后续修改并提交
    $ git commit xxx.rst
    $ git push

在上面这些工作完成后，是的，**再次恭喜！**

FAQ
--------------------------

为什么我的修改需要很长时间进行修改或等待合并？
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

请耐心等待。这可能需要花费几天时间来对你的pull request进行评估。
在合并后会也需要几个小时来等待你的文档在symfony.com得到更新。

如我我想翻译文档，我该怎么做？
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

阅读这篇专用文档 :doc:`document </contributing/documentation/translations>`。

为什么我要用最旧的维护分支文档（2.3）？
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

为了与Symfony代码保持一致，文档库被分成许多小分支，与不同的Symfony版本相对应。
``master`` 分支与最新的开发分支对应。

除非你在编写在Symfony ``2.3`` 版本后才最新引入的特性，你可以采用最新的版本分支，否则所有文档都应基于 ``2.3``。
文档管理员会用git把你的修改提交到对应可用的分支上。

如我我想提交一个未完成的文档？
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

你可以这样做。但是请使用这样两个前缀以使管理员了解你的工作进度：

* ``[WIP]`` (进行中) 被用于当你还未完全完成你的工作，但你想将其提交并被评估。
  在此情况下pull request不会被合并直到你完成它。

* ``[WCM]`` (等待代码合并) 被用于等待代码合并的过程中（通常新特性的添加或核心代码的修改），
  pull request随代码的合并而合并，拒绝而关闭。

是否接受一个含有大量修改的pull request？
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

首先，请确保修改至少是相关的，其次请分开创建pull request。
最好在提交前创建一个issue来询问文档管理员，他们是否接受你将提供的修改，因为他们是有可能拒绝你提交的修改的。
因此我们不想浪费你的时间。

.. _`github.com/symfony/symfony-docs`: https://github.com/symfony/symfony-docs
.. _reStructuredText: http://docutils.sourceforge.net/rst.html
.. _GitHub: https://github.com/
.. _`fork the repository`: https://help.github.com/articles/fork-a-repo
.. _`Symfony Documentation Contributors`: http://symfony.com/contributors/doc
.. _SensioLabsConnect: https://connect.sensiolabs.com/
.. _`Symfony Documentation Badge`: https://connect.sensiolabs.com/badge/36/symfony-documentation-contributor
.. _`sync your fork`: https://help.github.com/articles/syncing-a-fork