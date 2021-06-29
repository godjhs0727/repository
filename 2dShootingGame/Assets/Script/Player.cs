using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public bool isTouchTop;
    public bool isTouchBottom;
    public bool isTouchRight;
    public bool isTouchLeft;

    public int life;
    public int score;
    public float speed;
    public int maxPower;
    public int power;
    public int maxBoom;
    public int boom;

    public float maxShotDelay;
    public float curShotDelay;

    public GameObject bulletObjA;
    public GameObject bulletObjB;
    public GameObject boomEffect;

    public GameManager gameManger;
    public ObjectManager objectManager;
    public bool isHit;
    public bool isBoomTime;

    Animator anim;


    void Awake()
    {
        anim = GetComponent<Animator>();   
    }
    void Update()
    {
        Move();
        Fire();
        Boom();
        Reroad();
    }
    void Move()
    {
        float h = Input.GetAxisRaw("Horizontal");
        if ((h == 1 && isTouchRight) || (h == -1 && isTouchLeft))
            h = 0;
        float v = Input.GetAxisRaw("Vertical");
        if ((v == 1 && isTouchTop) || (v == -1 && isTouchBottom))
            v = 0;
        Vector3 curPos = transform.position;
        Vector3 nextPos = new Vector3(h, v, 0) * speed * Time.deltaTime; //transform 이동에는 Time.DeltaTime꼭 사용하기

        transform.position = curPos + nextPos;

        if (Input.GetButtonDown("Horizontal") || Input.GetButtonUp("Horizontal"))
        {
            anim.SetInteger("Input", (int)h);
        }
    }
    void Fire()
    {
        if (!Input.GetButton("Fire1"))
            return;
        if (curShotDelay < maxShotDelay)
            return;

        switch (power)
        {
            case 1:
                //Power One
                GameObject bullet = objectManager.MakeObj("BulletPlayerA");
                bullet.transform.position = transform.position;
                Rigidbody2D rigid = bullet.GetComponent<Rigidbody2D>();
                rigid.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 2:
                GameObject bulletR = objectManager.MakeObj("BulletPlayerA");
                bulletR.transform.position = transform.position + Vector3.right * 0.1f;
                GameObject bulletL = objectManager.MakeObj("BulletPlayerA");
                bulletL.transform.position = transform.position + Vector3.left * 0.1f;                
                Rigidbody2D rigidR = bulletR.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL = bulletL.GetComponent<Rigidbody2D>();
                rigidR.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 3:
                GameObject bulletRR = objectManager.MakeObj("BulletPlayerA");
                bulletRR.transform.position = transform.position + Vector3.right * 0.35f;                
                GameObject bulletC = objectManager.MakeObj("BulletPlayerB");
                bulletC.transform.position = transform.position;                
                GameObject bulletLL = objectManager.MakeObj("BulletPlayerA");
                bulletLL.transform.position = transform.position + Vector3.left * 0.35f;                
                Rigidbody2D rigidRR = bulletRR.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidC = bulletC.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidLL = bulletLL.GetComponent<Rigidbody2D>();
                rigidRR.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidC.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidLL.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 4:
                GameObject bulletR2 = objectManager.MakeObj("BulletPlayerB");
                bulletR2.transform.position = transform.position + Vector3.right * 0.35f;                    
                GameObject bulletCC = objectManager.MakeObj("BulletPlayerA");
                bulletCC.transform.position = transform.position;                
                GameObject bulletL2 = objectManager.MakeObj("BulletPlayerB");
                bulletL2.transform.position = transform.position + Vector3.left * 0.35f;                 
                Rigidbody2D rigidR2 = bulletR2.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidCC = bulletCC.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL2 = bulletL2.GetComponent<Rigidbody2D>();
                rigidR2.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidCC.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL2.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 5:
                GameObject bulletR3 = objectManager.MakeObj("BulletPlayerB");
                bulletR3.transform.position = transform.position + Vector3.right * 0.35f;
                GameObject bulletC3 = objectManager.MakeObj("BulletPlayerB");
                bulletC3.transform.position = transform.position;
                GameObject bulletL3 = objectManager.MakeObj("BulletPlayerB");
                bulletL3.transform.position = transform.position + Vector3.left * 0.35f;
                Rigidbody2D rigidR3 = bulletR3.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidC3 = bulletC3.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL3 = bulletL3.GetComponent<Rigidbody2D>();
                rigidR3.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidC3.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL3.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 6:
                GameObject bulletR4 = objectManager.MakeObj("BulletPlayerB");
                bulletR4.transform.position = transform.position + Vector3.right * 0.35f;
                GameObject bulletRR4 = objectManager.MakeObj("BulletPlayerA");
                bulletRR4.transform.position = transform.position + Vector3.right * 0.7f;
                GameObject bulletC4 = objectManager.MakeObj("BulletPlayerB");
                bulletC4.transform.position = transform.position;
                GameObject bulletL4 = objectManager.MakeObj("BulletPlayerB");
                bulletL4.transform.position = transform.position + Vector3.left * 0.35f;
                GameObject bulletLL4 = objectManager.MakeObj("BulletPlayerA");
                bulletLL4.transform.position = transform.position + Vector3.left * 0.7f;
                Rigidbody2D rigidR4 = bulletR4.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidRR4 = bulletRR4.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidC4 = bulletC4.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL4 = bulletL4.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidLL4 = bulletLL4.GetComponent<Rigidbody2D>();
                rigidR4.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidRR4.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidC4.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL4.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidLL4.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 7:
                GameObject bulletR5 = objectManager.MakeObj("BulletPlayerB");
                bulletR5.transform.position = transform.position + Vector3.right * 0.35f;                
                GameObject bulletRR5 = objectManager.MakeObj("BulletPlayerB");
                bulletRR5.transform.position = transform.position + Vector3.right * 0.7f;
                GameObject bulletC5 = objectManager.MakeObj("BulletPlayerB");
                bulletC5.transform.position = transform.position;
                GameObject bulletL5 = objectManager.MakeObj("BulletPlayerB");
                bulletL5.transform.position = transform.position + Vector3.left * 0.35f;
                GameObject bulletLL5 = objectManager.MakeObj("BulletPlayerB");
                bulletLL5.transform.position = transform.position + Vector3.left * 0.7f;
                Rigidbody2D rigidR5 = bulletR5.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidRR5 = bulletRR5.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidC5 = bulletC5.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL5 = bulletL5.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidLL5 = bulletLL5.GetComponent<Rigidbody2D>();
                rigidR5.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidRR5.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidC5.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL5.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidLL5.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
        }
        curShotDelay = 0;
    }
    void Reroad()
    {
        curShotDelay += Time.deltaTime; //딜레이 변수에 Time.deltaTime을 계속 더하여 시간계산

    }
    void Boom()
    {
        if (!Input.GetButton("Fire2"))
            return;
        if (isBoomTime)
            return;
        if (boom == 0)
            return;
        boom--;
        isBoomTime = true;
        gameManger.UpdateBoomIcon(boom);

        //#1.Effect visible
        boomEffect.SetActive(true);
        Invoke("OffBoomEffect", 3);

        //#2.Remove Enemy
        GameObject[] enemiesL = objectManager.GetPool("EnemyL");
        GameObject[] enemiesM = objectManager.GetPool("EnemyM");
        GameObject[] enemiesS = objectManager.GetPool("EnemyS");

        for (int index = 0; index < enemiesL.Length; index++)
        {
            if (enemiesL[index].activeSelf)
            {
                Enemy enemyLogic = enemiesL[index].GetComponent<Enemy>();
                enemyLogic.OnHit(1000);
            }
        }
        for (int index = 0; index < enemiesM.Length; index++)
        {
            if (enemiesM[index].activeSelf)
            {
                Enemy enemyLogic = enemiesM[index].GetComponent<Enemy>();
                enemyLogic.OnHit(1000);
            }
        }
        for (int index = 0; index < enemiesS.Length; index++)
        {
            if (enemiesS[index].activeSelf)
            {
                Enemy enemyLogic = enemiesS[index].GetComponent<Enemy>();
                enemyLogic.OnHit(1000);
            }
        }

        //#3.Remove EnemyBullet
        GameObject[] bulletsA = objectManager.GetPool("BulletEnemyA");
        GameObject[] bulletsB = objectManager.GetPool("BulletEnemyB");
        for (int index = 0; index < bulletsA.Length; index++)
        {
            if (bulletsA[index].activeSelf)
            {
                bulletsA[index].SetActive(false);
            }
        }
        for (int index = 0; index < bulletsB.Length; index++)
        {
            if (bulletsB[index].activeSelf)
            {
                bulletsB[index].SetActive(false);
            }
        }

    }
    void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.tag == "Border")
        {
            switch(collision.gameObject.name)
            {
                case "Top":
                    isTouchTop = true;
                    break;
                case "Bottom":
                    isTouchBottom = true;
                    break;
                case "Right":
                    isTouchRight = true;
                    break;
                case "Left":
                    isTouchLeft = true;
                    break;
            }
        }
        else if(collision.gameObject.tag == "Enemy" || collision.gameObject.tag == "EnemyBullet")
        {
            if (isHit)
                return;
            isHit = true;
            life--;
            gameManger.UpdateLifeIcon(life);

            if(life == 0)
            {
                gameManger.GameOver();
            }
            else
            {
                gameManger.RespawnPlayer();
            }
            gameObject.SetActive(false);
            collision.gameObject.SetActive(false);
        }
        else if(collision.gameObject.tag == "Item")
        {
            Item item = collision.GetComponent<Item>();
            switch(item.type)
            {
                case "Coin":
                    score += 1000;
                    break;
                case "Power":
                    if (power == maxPower)
                        score += 500;
                    else
                        power++;
                    break;
                case "Boom":
                    if (boom == maxBoom)
                        score += 500;
                    else
                    {
                        boom++;
                        gameManger.UpdateBoomIcon(boom);
                    }
                    break;
            }
            collision.gameObject.SetActive(false);
        }
    }

    void OffBoomEffect()
    {
        boomEffect.SetActive(false);
        isBoomTime = false;
    }
    void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Border")
        {
            switch (collision.gameObject.name)
            {
                case "Top":
                    isTouchTop = false;
                    break;
                case "Bottom":
                    isTouchBottom = false;
                    break;
                case "Right":
                    isTouchRight = false;
                    break;
                case "Left":
                    isTouchLeft = false;
                    break;
            }
        }
    }
}
