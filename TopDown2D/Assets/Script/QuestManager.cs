using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class QuestManager : MonoBehaviour
{
    public int questId;
    public int questActionIndex;
    public GameObject[] questObject;
    Dictionary<int, QuestData> questList;
    void Awake()
    {
        questList = new Dictionary<int, QuestData>();
        GenerateData();
    }
    void GenerateData()
    {
        questList.Add(10, new QuestData("마을 사람들과 대화하기."
                                        , new int[] { 1000, 2000}));
        questList.Add(20, new QuestData("루도의 동전 찾아주기."
                                        , new int[] { 5000, 2000 }));
        questList.Add(30, new QuestData("퀘스트 올 클리어!"
                                , new int[] { 0 }));
    }
    public int GetQuestTalkIndex(int id)
    {
        return questId + questActionIndex;
    }
    public string CheckQuest()
    {
        //Quest Name
        return questList[questId].questName;
    }
    public string CheckQuest(int id)
    {
        //Next Talk Target
        if (id == questList[questId].npcId[questActionIndex]) //id가 10인 것만 구분, questList를 통해서 [id==10]그다음 QuestData안의 npcID배열 인덱스 번호->.npcId[현재questActionIndex]
            questActionIndex++;
        
        //Control Quest Object
        ControlObject();

        //Talk Complete & Next Quest
        if (questActionIndex == questList[questId].npcId.Length) //전부 대화 했는지 확인, index는 계속 증가하기때문에 한도점, 마지막 npc와 대화하면 index는 배열의 길이와 같아짐
            NextQuest();

        //Quest Name
        return questList[questId].questName;
    }

    void NextQuest()
    {
        questId += 10; //questList가 2개 있는데 10만큼 차이가 나서 10+
        questActionIndex = 0; //다시 20의 퀘스트를 처리해야하기 때문에 0으로 초기화
    }
    void ControlObject()
    {
        switch(questId)
        {
            case 10:
                if (questActionIndex == 2) //루도랑 얘기가 끝나고 나면
                    questObject[0].SetActive(true); //비활성화되었던 코인 보이게 활성화
                break;
            case 20:
                if (questActionIndex == 1) //동전을 클릭하는 순간
                    questObject[0].SetActive(false); //동전 사라지게
                break;
        }
    }
}
