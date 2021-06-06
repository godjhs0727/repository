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
    public bool isAction;
    public int talkIndex;
    public Sprite prevPortrait;

    void Start()
    {
        questText.text = questManager.CheckQuest();
    }
    void Update()
    {
        //Sub Menu
        if (Input.GetButtonDown("Cancel"))
        {
            if (menuSet.activeSelf) //���� Active���¶��
                menuSet.SetActive(false);
            else
                menuSet.SetActive(true);
        }
    }
    public void Action(GameObject scanObj)
    {
        scanObject = scanObj;
        ObjectData objData = scanObject.GetComponent<ObjectData>();
        Talk(objData.id, objData.isNpc);

        talkPanel.SetBool("isShow", isAction);
    }
    void Talk(int id, bool isNpc)
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
            questText.text = questManager.CheckQuest(id); //�̾����� ����Ʈ�� ������ֱ� ���ؼ� questManager�� ����Ʈ ��ȣ�� ����
            return;
        }

        //Continue Talk
        if(isNpc)
        {
            talk.SetMsg(talkData.Split(':')[0]);

            //Show Portrait
            portraitImg.sprite = talkManager.GetPortrait(id, int.Parse(talkData.Split(':')[1]));
            portraitImg.color = new Color(1, 1, 1, 1);
            if (prevPortrait != portraitImg.sprite)
            {
                portraitAnim.SetTrigger("doEffect");
                prevPortrait = portraitImg.sprite;
            }
        }
        else //Npc�� �ƴҶ��� �ʻ�ȭ�� �����ϰ� ���̰� �ؼ� ������ ���� �Ⱥ��̰�
        {
            talk.SetMsg(talkData); //�ʻ�ȭ�� ������ index��ȣ�� ������ split���� �׳� talkData

            portraitImg.color = new Color(1, 1, 1, 0); 
        }

        isAction = true;
        talkIndex++;
    }
    public void GameSave()
    {

    }
    public void GameExit()
    {
        Application.Quit();
    }

}
