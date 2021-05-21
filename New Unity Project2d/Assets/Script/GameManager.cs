using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public int totalPoint;
    public int stagePoint;
    public int stageIndex;
    public int health;
    public PlayerMove player;
    public GameObject[] Stages;

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
        }
        //Calculate Point
        totalPoint += stagePoint;
        stagePoint = 0;
    }
    public void HealthDown()
    {
        if (health > 1)
            health--;
        else
        {
            player.OnDie();
            //Player Die Effect
            //Result UI
            //Retry Button UI
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
}
