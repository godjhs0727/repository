using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public int totalPoint;
    public int stagePoint;
    public int stageIndex;
    public int health;
    public PlayerMove player;
    public GameObject[] Stages;

    public Image[] UIhealth;
    public Text UIPoint;
    public Text UIStage;
    public GameObject RestartBtn;
    public GameObject[] Background;

    void Update()
    {
        UIPoint.text = (totalPoint + stagePoint).ToString();
        UIStage.text = UIStage.text = "STAGE " + (stageIndex + 1);
    }
    public void NextStage()
    {
        if (stageIndex < Stages.Length - 1)
        {
            Stages[stageIndex].SetActive(false);
            Background[stageIndex].SetActive(false);
            stageIndex++;
            Stages[stageIndex].SetActive(true);
            Background[stageIndex].SetActive(true);
            PlayerReposition();
            
        }
        else
        {
            Time.timeScale = 0;
            Text btnText = RestartBtn.GetComponentInChildren<Text>();
            btnText.text = "Game Clear!";
            RestartBtn.SetActive(true);
        }


        totalPoint += stagePoint;
        stagePoint = 0;
    }
    public void HealthDown()
    {
        if (health > 1)
        {
            health--;
            UIhealth[health].color = new Color(1, 0, 0, 0.2f);
        }
        else
        {
            UIhealth[0].color = new Color(1, 0, 0, 0.2f);
            player.OnDie();
            RestartBtn.SetActive(true);
        }
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            if (health > 1)
            {
                Animator anim = player.GetComponent<Animator>();
                anim.SetTrigger("Fall");

                PlayerReposition();
            }

            HealthDown();
        }
    }
    void PlayerReposition()
    {
        player.transform.position = new Vector3(0, 0, 0);
        player.VelocityZero();
    }
    public void Restart()
    {
        Time.timeScale = 1;
        SceneManager.LoadScene(0);
    }
}
