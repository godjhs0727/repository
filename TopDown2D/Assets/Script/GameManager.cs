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
            Debug.Log(questManager.CheckQuest(id)); //이어지는 퀘스트를 만들어주기 위해서 questManager의 퀘스트 번호를 증가
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
        else //Npc가 아닐때는 초상화가 투명하게 보이게 해서 있지만 눈에 안보이게
        {
            talkText.text = talkData; //초상화가 없으니 index번호도 없으니 split없이 그냥 talkData

            portraitImg.color = new Color(1, 1, 1, 0); 
        }

        isAction = true;
        talkIndex++;
    }

}
