# 위상 정렬

[메인으로 돌아가기](https://github.com/Altu-Bitu/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/2252" target="_blank">2252</a>|<a href="https://www.acmicpc.net/problem/2252" target="_blank">줄 세우기</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/1005" target="_blank">1005</a>|<a href="https://www.acmicpc.net/problem/1005" target="_blank">ACM Craft</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>|[바로가기]()||

## ✏️ 과제

### 필수
|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://programmers.co.kr/learn/courses/30/lessons/72415" target="_blank">2021 KAKAO BLIND RECRUITMENT</a>|<a href="https://programmers.co.kr/learn/courses/30/lessons/72415" target="_blank">카드 짝 맞추기</a>|Level 3|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/3085" target="_blank">3085</a>|<a href="https://www.acmicpc.net/problem/3085" target="_blank">사탕 게임</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[바로가기]()||

---

### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/2623" target="_blank">2623</a>|<a href="https://www.acmicpc.net/problem/2623" target="_blank">음악프로그램</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/2637" target="_blank">2637</a>|<a href="https://www.acmicpc.net/problem/2637" target="_blank">장난감 조립</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/23059" target="_blank">23059</a>|<a href="https://www.acmicpc.net/problem/23059" target="_blank">리그 오브 레게노</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/14907" target="_blank">14907</a>|<a href="https://www.acmicpc.net/problem/14907" target="_blank">프로젝트 스케줄링</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>|[바로가기]()||
|<a href="https://programmers.co.kr/learn/courses/30/lessons/67259" target="_blank">2020 카카오 인턴십</a>|<a href="https://programmers.co.kr/learn/courses/30/lessons/67259" target="_blank">경주로 건설</a>|Level 3|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/2638" target="_blank">2638</a>|<a href="https://www.acmicpc.net/problem/2638" target="_blank">치즈</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||

---

### 힌트
<details>
<summary>카드 짝 맞추기</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;카드의 양이 많지 않아요. 가능한 모든 카드 순서에 따라 커서 이동 횟수를 계산해도 괜찮아요. 각 카드는 2개의 카드가 한 쌍을 이루니 둘 중 어떤 카드를 먼저 뒤집을 지도 결정해야해요. 카드 순서를 정하는건 순열로 구할 수 있을거고, 한 쌍의 카드에서 어떤 카드를 먼저 뒤집을 지는 0 또는 1의 비트로 나타낼 수 있어요.
</div>
</details>

<details>
<summary>사탕 게임</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;범위가 크지 않으니 바꿀 수 있는 사탕을 하나하나 다 바꿔봐도 좋아요. 각 행과 열에서 먹을 수 있는 사탕의 수를 세는게 중요하겠네요.
</div>
</details>

<details>
<summary>음악프로그램</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;그래프가 주어지는 것이 아니네요! 입력을 통해 그래프를 만드는 것이 중요해 보여요. 예를 들어, 입력으로 들어오는 가수 순서에서 3번째 가수는 1, 2번째 가수와 모두 연관이 있죠.
</div>
</details>

<details>
<summary>장난감 조립</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;각 부품마다 필요한 부품을 저장하는 것이 중요해요. 중간 부품의 개수가 아닌 기본 부품의 개수를 저장해야 한다는 걸 주의해야 해요. 어떤 부품이 기본 부품이 될까요?
</div>
</details>

<details>
<summary>리그 오브 레게노</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;문자열을 인덱스로 그래프 관계를 정의하기 위해 사용해야 할 컨테이너가 무엇인지는 파악하셨을 거예요. 위상정렬은 여러가지 결과가 가능하다 했었죠! 하지만 이 문제는 스폐셜 저지가 걸려있지 않기 때문에 문제에서 원하는 순서대로 출력하는 것이 중요해요. 더불어 시간 관리도 까다로운 문제예요. 컨테이너 사용 시, 정렬을 해 줄 필요는 없으니까 이를 없앤 새로운 컨테이너를 사용해 보면 어떨까요?
</div>
</details>

<details>
<summary>프로젝트 스케줄링</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;비슷한 문제를 풀었으니 어떻게 풀어야 할지 감이 오실 것 같아요. 주의해야 할 점은 입력이네요! 이전 정점이 주어지지 않을 수 있으니 어떻게 입력 받아야 할까요? 더불어 마지막 정점은 한 개라는 보장이 없으니, 모든 작업을 하는 경우를 어떻게 처리해야 할지도 신경 써야 해요.
</div>
</details>

<details>
<summary>경주로 건설</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;하나의 위치에 대해 자동차가 진입할 수 있는 방향은 4개예요. 방향에 따른 건설 비용의 차이가 있으니 자동차가 어떤 방향에서 온 것인지 알아둬야 해요.
'+' 모양의 길이 있다고 할게요. 목표지점은 남쪽이고, 서쪽에 있는 차(A)와 북쪽에 있는 차(B)가 있어요. A의 건설 비용은 300이고, B의 건설 비용은 400이에요. 당장은 A가 더 적은 비용으로 경주로를 건설할 수 있지만, 중앙을 거쳐 남쪽으로 가기 위해 코너를 만들어야 하고, 비용은 1000이 될거예요. B는 코너를 만들 필요가 없으니 비용은 600이 되겠네요. 당장은 비효율적으로 보여도 모든 방향에 대한 비용을 기억해두세요!
</div>
</details>

<details>
<summary>치즈</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;치즈가 없는 공간이라고 해도 외부 공기와 접촉한 곳과 아닌 곳의 차이가 있어요. 외부 공간과 내부 공간을 어떻게 구분해야 할까요? 치즈가 녹다보면 새로운 외부 공간이 생기기도 할거예요. 각각의 시간마다 녹을 수 있는 치즈들은 모두 동시에 녹아야 한다는 것 잊지 마세요.
</div>
</details>

---
