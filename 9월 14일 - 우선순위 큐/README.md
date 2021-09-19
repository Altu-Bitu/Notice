# 우선순위 큐 (Priority Queue)

[메인으로 돌아가기](https://github.com/Altu-Bitu/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/11279" target="_blank">11279</a>|<a href="https://www.acmicpc.net/problem/11279" target="_blank">최대 힙</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[바로가기](https://github.com/Altu-Bitu/Notice/blob/main/9%EC%9B%94%2014%EC%9D%BC%20-%20%EC%9A%B0%EC%84%A0%EC%88%9C%EC%9C%84%20%ED%81%90/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/11279.cpp)|우선순위 큐|
|<a href="https://www.acmicpc.net/problem/2075" target="_blank">2075</a>|<a href="https://www.acmicpc.net/problem/2075" target="_blank">N번째 큰 수</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기](https://github.com/Altu-Bitu/Notice/blob/main/9%EC%9B%94%2014%EC%9D%BC%20-%20%EC%9A%B0%EC%84%A0%EC%88%9C%EC%9C%84%20%ED%81%90/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/2075.cpp)|우선순위 큐|

## ✏️ 과제

### 필수

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/11723" target="_blank">11723</a>|<a href="https://www.acmicpc.net/problem/11723" target="_blank">집합</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/6.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/3613" target="_blank">3613</a>|<a href="https://www.acmicpc.net/problem/3613" target="_blank">Java vs C++</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/6.svg"/>|[바로가기]()||

---

### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/2493" target="_blank">2493</a>|<a href="https://www.acmicpc.net/problem/2493" target="_blank">탑</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/7662" target="_blank">7662</a>|<a href="https://www.acmicpc.net/problem/7662" target="_blank">이중 우선순위 큐</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/11000" target="_blank">11000</a>|<a href="https://www.acmicpc.net/problem/11000" target="_blank">강의실 배정</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/11286" target="_blank">11286</a>|<a href="https://www.acmicpc.net/problem/11286" target="_blank">절댓값 힙</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/12018" target="_blank">12018</a>|<a href="https://www.acmicpc.net/problem/12018" target="_blank">Yonsei TOTO</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/15903" target="_blank">15903</a>|<a href="https://www.acmicpc.net/problem/15903" target="_blank">카드 합체 놀이</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[바로가기]()||


---

### 힌트

<details>
<summary>집합</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;20개의 숫자를 입력/삭제하는게 아니라 20개에 숫자에 체크/언체크 표시를 하는거라고 생각해볼까요?
</div>
</details>

<details>
<summary>Java vs C++</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;변수명이 C++ 형식에도 일치하고 Java 형식에도 일치하면 어떻게 되나요? 그리고 일단 에러가 나는 것부터 찾아볼까요?
</div>
</details>

<details>
<summary>탑</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;현재 탑보다 높고, 왼쪽에 위치한 탑 중에서 가장 가까운 탑이 레이저를 수신하는 탑이죠. 왼쪽 탑이 모두 현재 탑보다 낮다면 그 다음 탑들의 수신탑으로도 쓰일 일은 없어요!
</div>
</details>

<details>
<summary>이중 우선순위 큐</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;최대 힙과 최소 힙이 둘 다 필요할 것 같아요. 근데 한쪽에서 삭제된 데이터를 다른쪽에 반영하려면 어떻게 해야할까요? '어떤' 데이터가 삭제됐는지 저장할 방법은 없을까요? 그리고 이 문제는 셋으로도 풀 수 있어요.
</div>
</details>

<details>
<summary>강의실 배정</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;필요 강의실이 최소가 되려면 최대한 많은 수업을 이어서 해야겠죠. 이어서 수업이 가능한 강의실이 여러 개라면 어떤 강의실을 선택해야 강의실을 효율적으로 사용할 수 있을까요?
</div>
</details>

<details>
<summary>절댓값 힙</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;우선순위 큐에서 우선순위를 정의하는 방법을 알아보세요.
</div>
</details>

<details>
<summary>Yonsei TOTO</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;수강 신청에 성공하려면 최소한 l번째로 마일리지를 많이 넣은 사람보다는 마일리지를 더 넣어야겠죠? 만약 수강 인원이 미달이면 어떻게 될까요?
</div>
</details>

<details>
<summary>카드 합체 놀이</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;최종 결과가 최솟값이 되려면 어떤 카드를 뽑아야 할까요?
</div>
</details>
