# map の validation に関するメモ

## メモ
### ファイル
- `.cub`拡張子のファイルであること
- MAPは `0, 1, N, S, E, or W` で構成される
- 同じ情報が二重にないこと

###

mapのwall textureのvalidate
Floor, Ceiling の validate
map自体のvalidate
人が必ず1人いることのvalidate


## 課題文

◦ Your program must take as a first argument a scene description file with the .cub
extension.

◦ The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning　orientation.

This is a simple valid map:
111111
100101
101001
1100N1
111111

◦ The map must be closed/surrounded by walls, if not the program must return　an error.

◦ Except for the map content, each type of element can be separated by one or more empty line(s).

◦ Except for the map content which always has to be the last, each type of element can be set in any order in the file.

◦ Except for the map, each type of information from an element can be separated by one or more space(s).

◦ The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.

◦ Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as :

∗ North texture:
NO ./path_to_the_north_texture
· identifier: NO
· path to the north texure

∗ South texture:
SO ./path_to_the_south_texture
· identifier: SO
· path to the south texure

∗ West texture:
WE ./path_to_the_west_texture
· identifier: WE
· path to the west texure

∗ East texture:
EA ./path_to_the_east_texture
· identifier: EA
· path to the east texure

∗ Floor color:
F 220,100,0
· identifier: F
· R,G,B colors in range [0,255]: 0, 255, 255

∗ Ceiling color:
C 225,30,0
· identifier: C
· R,G,B colors in range [0,255]: 0, 255, 255

◦ Example of the mandatory part with a minimalist .cub scene:

NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

◦ If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice


/*
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
 */
