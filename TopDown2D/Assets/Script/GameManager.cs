using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public TalkManager talkManager;
    public QuestManager questManager;
    public Animator talkPanel;
    public Image portraitImg;
    public Animator portraitAnim;
    public TypeEffect talk;
    public Text questText;
    public GameObject scanObject;
    public GameObject menuSet;
    public GameObject player;
    public bool isAction;
    public int talkIndex;
    public Sprite prevPortrait;
    public Text nameText;

    void Start()
    {
        GameLoad();
        questText.text = questManager.CheckQuest();
    }
    void Update()
    {
        //Sub Menu
        if (Input.GetButtonDown("Cancel"))
        {
            SubMenuActive();
        }
    }
    public void SubMenuActive()
    {
        if (menuSet.activeSelf) //현재 Active상태라면
            menuSet.SetActive(false);
        else
            menuSet.SetActive(true);
    }
    public void Action(GameObject scanObj)
    {
        scanObject = scanObj;
        ObjectData objData = scanObject.GetComponent<ObjectData>();
        Talk(objData.id, objData.isNpc, objData.nameTag);

        talkPanel.SetBool("isShow", isAction);
    }
    void Talk(int id, bool isNpc, string nameTag)
    {
        int questTalkIndex = 0;
        string talkData = "";
        //Set Talk Data
        if (talk.isAnim)
        {
            talk.SetMsg("");
            return;
        }
        else
        {
            questTalkIndex = questManager.GetQuestTalkIndex(id); //10
            talkData = talkManager.GetTalk(id + questTalkIndex, talkIndex); //1000 + 10, 0
        }
        //End Talk
        if (talkData == null)
        {
            isAction = false;
            talkIndex = 0;
            questText.text = questManager.CheckQuest(id); //이어지는 퀘스트를 만들어주기 위해서 questManager의 퀘스트 번호를 증가
            return;
        }

        //Continue Talk
        if(isNpc)
        {
            talk.SetMsg(talkData.Split(':')[0]);
            nameText.text = nameTag;

            //Show Portrait
            portraitImg.sprite = talkManager.GetPortrait(id, int.Parse(talkData.Split(':')[1]));
            portraitImg.color = new Color(1, 1, 1, 1);
            if (prevPortrait != portraitImg.sprite)
            {
                portraitAnim.SetTrigger("doEffect");
                prevPortrait = portraitImg.sprite;
            }
        }
        else //Npc가 아닐때는 초상화가 투명하게 보이게 해서 있지만 눈에 안보이게
        {
            nameText.text = "";
            talk.SetMsg(talkData); //초상화가 없으니 index번호도 없으니 split없이 그냥 talkData

            portraitImg.color = new Color(1, 1, 1, 0); 
        }

        isAction = true;
        talkIndex++;
    }
    public void GameSave()
    {
        PlayerPrefs.SetFloat("PlayerX", player.transform.position.x); //PlayerPOrefs:간단한 데이터 저장을 지원하는 클래스
        PlayerPrefs.SetFloat("PlayerY", player.transform.position.y);
        PlayerPrefs.SetFloat("QuestId", questManager.questId);
        PlayerPrefs.SetFloat("QuestActionIndex", questManager.questActionIndex);
        PlayerPrefs.Save();
        menuSet.SetActive(false);
        //player.x, player.y
        //Quest Id
        //Quest Action Index
    }
    public void GameLoad()
    {
        if (!PlayerPrefs.HasKey("PlayerX")) //PlayerX를 저장한적이 없으면
            return;
        float x = PlayerPrefs.GetFloat("PlayerX");
        float y = PlayerPrefs.GetFloat("PlayerY");
        int questId = PlayerPrefs.GetInt("QuestId");
        int questActionIndex = PlayerPrefs.GetInt("QuestActionIndex");

        player.transform.position = new Vector3(x, y, 0);
        questManager.questId = questId;
        questManager.questActionIndex = questActionIndex;
        questManager.ControlObject();
    }
    public void GameExit()
    {
        Application.Quit();
    }

}
