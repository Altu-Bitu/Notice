# 동적 계획법과 최단 거리 역추적

[메인으로 돌아가기](https://github.com/Altu-Bitu/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/11779" target="_blank">11779</a>|<a href="https://www.acmicpc.net/problem/11779" target="_blank">최소비용 구하기2</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/13913" target="_blank">13913</a>|<a href="https://www.acmicpc.net/problem/13913" target="_blank">숨바꼭질 4</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/14002" target="_blank">14002</a>|<a href="https://www.acmicpc.net/problem/14002" target="_blank">가장 긴 증가하는 부분 수열 4</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||

## ✏️ 과제

### 필수
|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/16964" target="_blank">16964</a>|<a href="https://www.acmicpc.net/problem/16964" target="_blank">DFS 스페셜 저지</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/1719" target="_blank">1719</a>|<a href="https://www.acmicpc.net/problem/1719" target="_blank">택배</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||

---

### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/11780" target="_blank">11780</a>|<a href="https://www.acmicpc.net/problem/11780" target="_blank">플로이드 2</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/12852" target="_blank">12852</a>|<a href="https://www.acmicpc.net/problem/12852" target="_blank">1로 만들기 2</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/9019" target="_blank">9019</a>|<a href="https://www.acmicpc.net/problem/9019" target="_blank">DSLR</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/9252" target="_blank">9252</a>|<a href="https://www.acmicpc.net/problem/9252" target="_blank">LCS 2</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||

---

### 힌트

<details>
<summary>택배</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;어떤 알고리즘을 써야하는지는 아실거라고 생각하겠습니다. 경로 i, j 사이에 포함될 수 있는 중간 경로 k가 생긴다면 어떻게 반영해야 할까요? 만약 둘 사이의 경로가 i->t->k->j라면요?
</div>
</details>

<details>
<summary>DFS 스페셜 저지</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;한 정점에 연결된 서로 다른 두 정점 i, j가 있다고 할게요. 만약 i를 j보다 먼저 탐색했다면 최종 경로는 어떻게 될까요? 연결된 정점들에 대해 어떤 순서로 탐색하게 되는지 생각해보세요. 탐색 결과를 보면 연결된 정점의 순서도 알 수 있어요.
</div>
</details>

<details>
<summary>LCS 2</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;LCS는 지난 동적계획법을 배우면서 설명한 적이 있어요. 지난 수업자료를 다시 참고해볼까요? 거기서 경로를 저장하는 부분만 추가하면 될 것 같아요. 역추적을 하기 위해선 위치 값이 아닌, 무엇을 저장해야 할까요?
</div>
</details>

<details>
<summary>플로이드 2</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;플로이드-워셜의 경로를 찾는 문제네요. 어렵다면 같이 과제로 나간 "택배"문제를 먼저 풀어보아요! 이 문제는 택배 문제완 다르게 역추적을 하기 위해서 경로표를 조금 다르게 작성해야 해요.
</div>
</details>

<details>
<summary>DSLR</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;경로와 명령어를 함께 저장해야 하네요. 배열을 사용해서 역추적도 가능하지만, 튜터링 때 최단거리 역추적은 큐를 활용해서 경로를 저장할 수도 있다고 했었죠.
</div>
</details>

<details>
<summary>1로 만들기 2</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;점화식만 세우면 거의 푼 문제예요. 역추적을 위해 인덱스를 무엇으로 사용해서 경로 배열을 만들어야 할까요?
</div>
</details>

---
