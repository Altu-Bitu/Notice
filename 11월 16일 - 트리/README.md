# 트리(Tree)

[메인으로 돌아가기](https://github.com/Altu-Bitu/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/1991" target="_blank">1991</a>|<a href="https://www.acmicpc.net/problem/1991" target="_blank">트리 순회</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/4803" target="_blank">4803</a>|<a href="https://www.acmicpc.net/problem/4803" target="_blank">트리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://programmers.co.kr/learn/courses/30/lessons/72416" target="_blank">2021 KAKAO BLIND RECRUITMENT</a>|<a href="https://programmers.co.kr/learn/courses/30/lessons/72416" target="_blank">매출 하락 최소화</a>|level 4|[바로가기]()||

## ✏️ 과제

### 필수
|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/2250" target="_blank">2250</a>|<a href="https://www.acmicpc.net/problem/2250" target="_blank">트리의 높이와 너비</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/14675" target="_blank">14675</a>|<a href="https://www.acmicpc.net/problem/14675" target="_blank">단절점과 단절선</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||

---

### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/20924" target="_blank">20924</a>|<a href="https://www.acmicpc.net/problem/20924" target="_blank">트리의 기둥과 가지</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/1967" target="_blank">1967</a>|<a href="https://www.acmicpc.net/problem/1967" target="_blank">트리의 지름</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/5639" target="_blank">5639</a>|<a href="https://www.acmicpc.net/problem/5639" target="_blank">이진 검색 트리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/15681" target="_blank">15681</a>|<a href="https://www.acmicpc.net/problem/15681" target="_blank">트리와 쿼리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||

---

### 힌트

<details>
<summary>트리의 높이와 너비</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;레벨과 열 번호를 모두 구해야 하네요. 그래도 레벨은 트리를 순회하며 비교적 쉽게 구할 수 있어요. 이때 열 번호도 순회 과정을 활용해서 구할 수 있어요. 알고 있는 트리의 순회를 모두 돌려보며 어떤 순회 방식이 열 번호를 구하는 것과 연관이 있는지 찾아봅시다.
</div>
</details>

<details>
<summary>단절점과 단절선</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;트리의 성질만 파악하고 계시다면 아주 쉽게 풀 수 있어요. 어떤 경우에 단절선, 단절점을 만족하며 트리는 어떤 성질을 가지고 있을까요?
</div>
</details>

<details>
<summary>트리의 기둥과 가지</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;일단 기가 노드의 위치부터 찾아야겠네요. 문제에도 나와있지만, 기가 노드가 될 수 있는 경우의 수가 여러 개라는거 유념해주세요. 가장 긴 가지는 어떻게 구할까요? PPT에 힌트가 있습니다! 그리고 문제 정말 잘 읽으셔야해요!!
</div>
</details>

<details>
<summary>트리의 지름</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;지름을 이루는 두 정점을 동시에 찾을 순 없어요. 임의의 모든 정점에서 가장 멀리 있는 정점들은 어떤걸까요? 그 정점들엔 어떤 공통점이 있나요? 지름의 길이를 구하려면 자식->부모 방향으로 거슬러 올라가야 할 수도 있겠어요. 그림에 힌트가 아주 많아요!
</div>
</details>

<details>
<summary>이진 검색 트리</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;여러가지의 순회 결과를 보고 트리의 모습을 유추해본 적 있어요. 하지만 이번엔 순회 결과가 하나만 주어지네요? 우리가 알 수 없는 정보는 어떤걸까요? 왜 하필 트리가 BST인걸까요? 아니면 BST를 직접 만들어도 됩니다! BST에 정점을 추가하는 것도 배웠었어요.
</div>
</details>

<details>
<summary>트리와 쿼리</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;매번 특정 정점을 루트로 하는 서브트리의 정점 수를 구하기엔 시간이 너무 오래 걸려요. 모든 서브트리의 정점 수를 어딘가 '저장'해둘 수는 없을까요? 문제가 기네요. 그만큼 힌트도 많이 있습니다! (PPT에도 있구요)
</div>
</details>

---
