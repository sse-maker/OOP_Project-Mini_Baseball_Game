# OOP_Project-Mini_Baseball_Game
OOP_Project-Mini_Baseball_Game

# Mini Baseball Game
본 게임은 야구의 모든 룰을 적용하지 않은 ‘미니 야구 게임’이다. 컴퓨터와 플레이어가 플레이를 하게 된다. 총 3회로 게임을 진행하며, 플레이어는 타자가 되어 컴퓨터가 던지는 공을 치거나 거를 수 있으며 3회가 종료되고 특정 점수 이상을 획득하면 플레이어가 이기는 게임이다.

## ‘미니 야구 게임’ 규칙
- 컴퓨터는 일정한 확률로 스트라이크와 볼인 공을 던진다.
- 플레이어(타자)는 컴퓨터가 던진 공을 치기 위해 스윙을 하거나 공을 거를 수 있다. 아래의 기준으로 ‘스윙’ 혹은 ‘거르기’를 선택할 수 있다.
- 플레이어가 스윙을 하여 안타를 치거나 볼넷의 경우, 타자는 진출한다. 안타를 친 경우, 특정한 확률로 1루타, 2루타, 3루타, 홈런 그리고 플라이 아웃이 발생하며, 각각 안타에 따라 주자들이 이동(진루)한다.
  
  ### 이동 및 점수 득점 규칙
  1) 1루타의 경우 모든 주자가 하나의 베이스만큼 이동한다.
    - 1루에 주자가 존재하면 2루로 진루(이동)한다.
    - 2루에 주자가 존재하면 3루로 진루(이동)한다.
    - 3루에 주자가 존재하면 홈베이스로 진루(이동)한다.
  2) 2루타의 경우 모든 주자는 두 개의 베이스만큼 이동한다.
  3) 3루타의 경우 모든 주자는 세 개의 베이스만큼 이동한다.
  4) 홈런의 경우 모든 주자(타자 포함)가 홈 베이스로 들어온다.
  5) 볼넷의 경우 타자가 1루로 진출한다.
    - 1,2,3루에 모두 주자가 있는 상황에서 타자가 볼넷을 얻은 경우라면, 모든 주자가 하나의 베이스만큼 이동한다. 타자는 1루에, 1루 주자는 2루에, 2루 주자는 3루에, 3루 주자는 홈으로 들어와 득점한다.
    - 진루하고자 하는 베이스에 주자가 없는 경우라면, 그 베이스 다음 주자들은 이동하지 않는다. (ex. 주자가 2, 3루에 있는 경우, 현재 타자가 볼넷으로 출루하게 되면 2, 3루의 주자는 다음 베이스로 이동하지 않는다.)
  6) 한 명의 주자가 1,2,3루를 순서대로 거쳐 홈베이스로 들어온 경우, 1점 득점한다. 즉, 홈베이스로 들어온 주자의 수만큼 점수를 획득하게 된다.

- 플레이어가 스윙을 하여 공을 쳐서 플라이 아웃 또는 삼진(쓰리 스트라이크)이 된 경우, 그리고 공을 걸렀을 때 스트라이크가 되어 삼진이 되면 타자가 아웃된다.
  
  ### 아웃 규칙
  - 플레이어가 컴퓨터가 던진 공을 타격하면 일정한 확률로 플라이 아웃 처리가 된다.
  - 플레이어가 삼진(3 스트라이크)을 당하면 아웃 처리가 된다.
  - 주자에 의한 아웃은 존재하지 않으며, 스윙 후 플라이 아웃, 쓰리 스트라이크에 의한 아웃만 존재한다.
  
- 쓰리 아웃이 되면 한 회가 종료되며, 3회가 모두 끝나면 획득한 점수를 기준으로 승/패가 결정된다.
- 3회가 종료되기 전에 획득한 점수가 기준 점수를 넘을 시, 해당 이닝이 끝나면 게임 종료와 함께 승리 메시지를 출력한다.
