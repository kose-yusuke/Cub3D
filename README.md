# Cub3D

## 実行方法

./cub3D *.cub

## 課題概要

一人称視点で迷路の中をリアルな3Dグラフィックで表現する。
この表現は、レイキャスティングの原則を使用して作成する必要がある。

## 使用可能な関数一覧

### ファイルとディレクトリ操作
- open: ファイルを開いてファイル記述子を取得する
- close: 開いたファイル記述子を閉じる
- read: ファイル記述子からデータを読み込む
- write: ファイル記述子にデータを書き込む
### 出力とメモリ管理
- printf: 形式付き出力を行う
- malloc: メモリを動的に割り当てる
- free: メモリを解放する
### エラー処理
- strerror: エラーメッセージを返す
### プロセス管理
- exit: プロセスを終了し、ステータスコードを返す
### 時間情報の取得
- gettimeofday: 時刻を取得/設定する

## 必須項目:
・地図内のスペースで区切り可能
- minilibxを使用する。
- 壁の向き（北、南、東、西）に応じて異なる壁のテクスチャ（選択は自由）を表示する。
- 別のウィンドウへの変更、最小化など、window操作はスムーズに実装する。
- 床と天井は2つの異なる色を使用する。
- ←→キーで左右の視点を移動する。
- WASDキーで移動する。
- ESCキーもしくは左上のxマークを押すとウィンドウが閉じる。
- 地図は「0」（空間）、「1」（壁）、及び「NSWE」（プレイヤーのスポーン地点と向き）で構成される。
- 地図が壁(1)で囲まれていない場合、エラー表示する。

## ボーナス項目:
・壁の衝突判定
・ミニマップ
・マウスによる視点移動
・ドアの開閉
・スプライト表示
