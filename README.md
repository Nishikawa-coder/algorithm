# Bubblesort
### 概要
隣あう要素の大小を末尾から比較しながら整理させ、昇順にソートさせる。
# Bucketsort
### 概要
数列の要素値の種類の数だけバケツを用意し数列の各要素を対応するバケツに投入する。その後、各バケツ内の要素を後から順に書き出す事で昇順にソートされた数列を出力する。
### 苦労した点・工夫した点
構造体・連結リスト・ポインタの理解に苦労したがこれは授業のスライドやサイトなどで図的に考える事で理解を深めた。
# Heapsort
### 概要
入力された数列の要素を順番にヒープに追加してからヒープから最小値を次々に削除しつつ並べることで昇順にソートされた数列を出力する。
### 苦労した点・工夫した点
・Insertにおいて最初値xの入る場所をwhile文で回してきめるようにしていたが、先生の例を参考にさせていただいて再帰関数の形にする事でより簡潔な形となった。

・Deliteminにおいて最初左の子を交換する場合と右の子を交換する場合とでif文で分けてコードを書いていたが、長々と内容が重複する形になったり読みづらかったりしたので、 
予め左の子か右の子どっちと交換する方を決めてそれをcに入れて親との比較をする事でコードが簡潔になった。
# Mergesort
### 概要
配列を小さい配列に分解してから順に併合し、二つの配列の先頭から小さい数値を抽出していき、全体として昇順にソートする。
### 苦労した点・工夫した点
再帰関数を理解するのに苦労した。→図的に説明しているサイトなどを拝見して概要理解に努めた。
# Quicksort
### 概要
分割する軸要素pを決めてp未満とそれ以外とに数列を分割すると言うのを再帰的に繰り返す事で最終的に昇順にソートされた数列を出力する。
### 苦労した点・工夫した点
verifysortedやpivot、partitionは予め授業内で説明された関数であり理解しやすい内容だったので特に苦労した点はない。
# Strcmp
### 概要
二つの文字列（最初に入力する文字数>=次に入力する文字数　である前提）を比較してどれだけ修正する必要があるかを出力する。
### 苦労した点・工夫した点
最初コードの30行目であっていない数を数えるようにしていたがそれだと空白と文字の比較の時に数え上げられないので、あっている数を数えてから最初の文字列の文字数との差を取って求めるようにした。

# 作成者
西川凜