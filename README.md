## 組別
第三組

## 成員資料
資工4B 黃宣迪

## 專題題目
貪食蛇

# 程式介紹
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%20Position.png)


![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%20SnakeGame.png)
## 變數解釋
width: int - 遊戲畫面寬度，定義遊戲區域的橫向大小。

height: int - 遊戲畫面高度，定義遊戲區域的縱向大小。

snakeHead: Position - 蛇頭的位置，使用Position結構體表示。

snakeBody: vector<Position> - 蛇身的位置，使用vector儲存每個身體節點的位置。

food: Position - 食物的位置，使用Position結構體表示。

gameOver: bool - 遊戲是否結束的標誌，true表示遊戲結束，false表示遊戲進行中。

paused: bool - 遊戲是否暫停的標誌，true表示暫停，false表示運行中。

score: int - 玩家得分，隨著吃到食物而增加。

gameSpeed: int - 遊戲速度，控制蛇移動的速度，數值越小速度越快。

level: int - 遊戲等級，隨著得分的提高而增加。

## SnakeGame()
為建構函數，初始化隨機生成器和把gameOver跟paused設置為false
## HideCursor()
將控制台的光標隱藏
## GotoXY(int x, int y)
將控制台光標移動到指定的(x, y)位置
## IsFoodOnSnake(const Position& pos)
檢查食物是否在蛇身上
## IsFoodInCorner(const Position& pos)
檢查食物是否在遊戲區域的四個角落
## GenerateFood()
生成新的食物位置。使用隨機數生成器生成食物的(x, y)坐標，並確保食物不在蛇身上或者角落
## Setup(bool isFirstTime)
設置或重置遊戲。設置基本變量，設置蛇頭位置在遊戲區域的中心，並清除蛇身。生成新的食物，重置分數、遊戲速度和級別。如果不是第一次遊戲，則執行倒計時。
## Draw() 
繪製遊戲畫面
## ShowLevelUp() 
顯示升級消息
## CountDown()
進行遊戲開始前的倒計時。從3倒數到1
## PauseMenu()
顯示暫停畫面包含繼續遊戲和重新開始
## ClearPauseMenu()
把暫停畫面清除
## GameOverMenu()
顯示遊戲結束畫面包含重新開始和結束程式
## ClearGameOverMenu()
把遊戲結束畫面清除
## Input()
處理玩家輸入，控制蛇的方向跟暫停遊戲
## Logic()
設置遊戲的邏輯，判斷遊戲是否暫停，根據當前方向控制蛇頭，檢查蛇頭是否有撞到牆或自己的身體，如果蛇頭吃到食物，增加分數，並生成新的食物。如果蛇頭沒有吃到食物，移動蛇身。
## GetGameSpeed()
獲得當前遊戲速度
# 程式執行
進入程式後會先顯示下圖
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20102836.png)
進入遊戲 遊戲畫面顯示上方的遊戲內容 框中有貪食蛇的本體和他的目標 下方有目前分數與等級
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20102854.png)
吃掉目標 分數加10分 同時貪食蛇蛇身變長一格
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20102914.png)
每50分 level增加
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20102932.png)
顯示等級2 同時貪食蛇速度加快 最高等級為10
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20102942.png)
按下空白鍵暫停遊戲 出現選項 按下1或2選擇繼續遊戲或是重新開始
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20102949.png)
選擇完畢後會有3秒的倒數
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20102959.png)
撞到牆壁或是撞到貪食蛇自己的身體 遊戲結束 會出現選項 按下1或2選擇重新開始或是結束程式
![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20103029.png)

![image](https://github.com/chichi-coconut/-/blob/picture/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-06-16%20103041.png)


