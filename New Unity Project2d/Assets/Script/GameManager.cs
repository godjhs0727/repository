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
    public Text Point;
    public Text Stage;
    public GameObject RestartBtn;

    void Update()
    {
        Point.text = (totalPoint + stagePoint).ToString();
    }

    public void NextStage()
    {
        //Change Stage
        if(stageIndex < Stages.Length - 1)
        {
            Stages[stageIndex].SetActive(false);
            stageIndex++;
            Stages[stageIndex].SetActive(true);
            PlayerReposition();
        }
        else
        {
            //Game Clear
            //Player Control Lock
            Time.timeScale = 0; //¿ÏÁÖÇÏ¸é ½Ã°£ÀÌ ¸ØÃã
            Text btnText = RestartBtn.GetComponentInChildren<Text>();
            btnText.text = "Game Clear!";
            RestartBtn.SetActive(true);
        }
        //Calculate Point
        totalPoint += stagePoint;
        stagePoint = 0;

        Stage.text = "STAGE " + (stageIndex + 1);
    }
    public void HealthDown()
    {
        if (health > 1)
        {
            health--;
            UIhealth[health].color = new Color(1, 0, 0, 0.4f);
            player.PlaySound("DAMAGED");
        }
        else
        {
            UIhealth[0].color = new Color(1, 0, 0, 0.4f);
            //Player Die Effect
            player.OnDie();
            //Result UI
            //Retry Button UI
            RestartBtn.SetActive(true);
        }
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {

            //Player Reposition
            if (health > 1)
                PlayerReposition();

            //Health Down
            HealthDown();

        }
    }

    void PlayerReposition()
    {
        player.transform.position = new Vector3(-9, 1, 0);
        player.VelocityZero();
    }

    public void Restart()
    {
        Time.timeScale = 1;
        SceneManager.LoadScene(0);
    }
}
