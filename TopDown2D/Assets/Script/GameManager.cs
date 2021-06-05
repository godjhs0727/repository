using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public TalkManager talkManager;
    public QuestManager questManager;
    public GameObject talkPanel;
    public Image portraitImg;
    public Text talkText;
    public GameObject scanObject;
    public bool isAction;
    public int talkIndex;

    void Start()
    {
        Debug.Log(questManager.CheckQuest());
    }
    public void Action(GameObject scanObj)
    {
        scanObject = scanObj;
        ObjectData objData = scanObject.GetComponent<ObjectData>();
        Talk(objData.id, objData.isNpc);

        talkPanel.SetActive(isAction);
    }
    void Talk(int id, bool isNpc)
    {
        //Set Talk Data
        int questTalkIndex = questManager.GetQuestTalkIndex(id); //10
        string talkData = talkManager.GetTalk(id + questTalkIndex, talkIndex); //1000 + 10, 0

        //End Talk
        if (talkData == null)
        {
            isAction = false;
            talkIndex = 0;
            Debug.Log(questManager.CheckQuest(id)); //�̾����� ����Ʈ�� ������ֱ� ���ؼ� questManager�� ����Ʈ ��ȣ�� ����
            return;
        }

        //Continue Talk
        if(isNpc)
        {
            talkText.text = talkData.Split(':')[0];

            //Show Portrait
            portraitImg.sprite = talkManager.GetPortrait(id, int.Parse(talkData.Split(':')[1]));
            portraitImg.color = new Color(1, 1, 1, 1);
        }
        else //Npc�� �ƴҶ��� �ʻ�ȭ�� �����ϰ� ���̰� �ؼ� ������ ���� �Ⱥ��̰�
        {
            talkText.text = talkData; //�ʻ�ȭ�� ������ index��ȣ�� ������ split���� �׳� talkData

            portraitImg.color = new Color(1, 1, 1, 0); 
        }

        isAction = true;
        talkIndex++;
    }

}
