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
        questList.Add(10, new QuestData("���� ������ ��ȭ�ϱ�."
                                        , new int[] { 1000, 2000}));
        questList.Add(20, new QuestData("�絵�� ���� ã���ֱ�."
                                        , new int[] { 5000, 2000 }));
        questList.Add(30, new QuestData("����Ʈ �� Ŭ����!"
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
        if (id == questList[questId].npcId[questActionIndex]) //id�� 10�� �͸� ����, questList�� ���ؼ� [id==10]�״��� QuestData���� npcID�迭 �ε��� ��ȣ->.npcId[����questActionIndex]
            questActionIndex++;
        
        //Control Quest Object
        ControlObject();

        //Talk Complete & Next Quest
        if (questActionIndex == questList[questId].npcId.Length) //���� ��ȭ �ߴ��� Ȯ��, index�� ��� �����ϱ⶧���� �ѵ���, ������ npc�� ��ȭ�ϸ� index�� �迭�� ���̿� ������
            NextQuest();

        //Quest Name
        return questList[questId].questName;
    }

    void NextQuest()
    {
        questId += 10; //questList�� 2�� �ִµ� 10��ŭ ���̰� ���� 10+
        questActionIndex = 0; //�ٽ� 20�� ����Ʈ�� ó���ؾ��ϱ� ������ 0���� �ʱ�ȭ
    }
    void ControlObject()
    {
        switch(questId)
        {
            case 10:
                if (questActionIndex == 2) //�絵�� ��Ⱑ ������ ����
                    questObject[0].SetActive(true); //��Ȱ��ȭ�Ǿ��� ���� ���̰� Ȱ��ȭ
                break;
            case 20:
                if (questActionIndex == 1) //������ Ŭ���ϴ� ����
                    questObject[0].SetActive(false); //���� �������
                break;
        }
    }
}
