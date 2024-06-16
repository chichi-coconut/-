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
## 程式執行
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


