# 백트래킹 (Backtracking)

[메인으로 돌아가기](https://github.com/Altu-Bitu/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크 1|풀이 링크 2|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/15649" target="_blank">15649</a>|<a href="https://www.acmicpc.net/problem/15649" target="_blank">N과 M (1)</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[바로가기](https://github.com/Altu-Bitu/Notice/blob/main/9%EC%9B%94%2024%EC%9D%BC%20-%20%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/15649.cpp)||백트래킹|
|<a href="https://www.acmicpc.net/problem/15650" target="_blank">15650</a>|<a href="https://www.acmicpc.net/problem/15650" target="_blank">N과 M (2)</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[바로가기](https://github.com/Altu-Bitu/Notice/blob/main/9%EC%9B%94%2024%EC%9D%BC%20-%20%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/15650.cpp)|[바로가기](https://github.com/Altu-Bitu/Notice/blob/main/9%EC%9B%94%2024%EC%9D%BC%20-%20%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/15650_2.cpp)|백트래킹, 조합|
|<a href="https://www.acmicpc.net/problem/9663" target="_blank">9663</a>|<a href="https://www.acmicpc.net/problem/9663" target="_blank">N-Queen</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기](https://github.com/Altu-Bitu/Notice/blob/main/9%EC%9B%94%2024%EC%9D%BC%20-%20%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/9663.cpp)|[바로가기](https://github.com/Altu-Bitu/Notice/blob/main/9%EC%9B%94%2024%EC%9D%BC%20-%20%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/9663_2.cpp)|백트래킹|


## ✏️ 과제

---

### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/15661" target="_blank">15661</a>|<a href="https://www.acmicpc.net/problem/15661" target="_blank">링크와 스타트</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/15665" target="_blank">15665</a>|<a href="https://www.acmicpc.net/problem/15665" target="_blank">N과 M (11)</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/2529" target="_blank">2529</a>|<a href="https://www.acmicpc.net/problem/2529" target="_blank">부등호</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/10971" target="_blank">10971</a>|<a href="https://www.acmicpc.net/problem/10971" target="_blank">외판원 순회 2</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/2580" target="_blank">2580</a>|<a href="https://www.acmicpc.net/problem/2580" target="_blank">스도쿠</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/1759" target="_blank">1759</a>|<a href="https://www.acmicpc.net/problem/1759" target="_blank">암호 만들기</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||

---

### 힌트

<details>
<summary>링크와 스타트</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;팀을 나누기만 한다면 계산은 쉬워 보여요. 우선 한 팀에 배치하는 경우로 생각해 볼까요?
</div>
</details>

<details>
<summary>N과 M (11)</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;수를 여러 번 사용하는게 가능해졌네요! 기존의 check 배열을 어떻게 활용하면 좋을까요? 여러 번 사용이 가능하다 해도 제한이 있기 마련이죠!
</div>
</details>

<details>
<summary>부등호</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;한 번에 부등호를 만족시키는 수를 찾는 건 어려워 보여요. 우선 수열을 만들다가 정답이 안되는 경우라면 가지치기를 해볼까요? 생각이 안나면, 가장 쉬운 길을 선택해도 좋아요
</div>
</details>

<details>
<summary>외판원 순회 2</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;일단 방문할 수 있는 도시를 차례차례 방문해볼까요? 시작 도시로 다시 되돌아와야 한다는거 잊지마세요! 그럼 어디부터 시작했는지 알고 있어야겠네요!
</div>
</details>

<details>
<summary>스도쿠</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;아주 익숙한 스도쿠입니다! 스도쿠 문제를 풀 때 어떻게 했었나요? 일단 가능한 숫자를 넣어보고 안되면 다른 숫자를 넣어봐요! 그나저나 같은 구역인지는 어떻게 알까요? 같은 구역의 크기는 3x3 이네요!
</div>
</details>

<details>
<summary>암호 만들기</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;암호가 증가하는 순서로 배열하는 건 수업시간에 배운 문제를 그대로 활용할 수 있어 보여요. 거기에 모음과 자음의 개수에 대한 조건만 추가됐네요! 어렵다면 조합으로 접근해봐도 좋아요
</div>
</details>


---
