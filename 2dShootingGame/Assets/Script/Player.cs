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

    public GameManager manager;
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
        Vector3 nextPos = new Vector3(h, v, 0) * speed * Time.deltaTime; //transform �̵����� Time.DeltaTime�� ����ϱ�

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
                GameObject bullet = Instantiate(bulletObjA, transform.position, transform.rotation); //Destroy�� �ݴ�, ����
                Rigidbody2D rigid = bullet.GetComponent<Rigidbody2D>();
                rigid.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 2:
                GameObject bulletR = Instantiate(bulletObjA, transform.position + Vector3.right * 0.1f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletL = Instantiate(bulletObjA, transform.position + Vector3.left * 0.1f, transform.rotation);
                Rigidbody2D rigidR = bulletR.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL = bulletL.GetComponent<Rigidbody2D>();
                rigidR.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 3:
                GameObject bulletRR = Instantiate(bulletObjA, transform.position + Vector3.right * 0.35f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletC = Instantiate(bulletObjB, transform.position, transform.rotation);
                GameObject bulletLL = Instantiate(bulletObjA, transform.position + Vector3.left * 0.35f, transform.rotation);
                Rigidbody2D rigidRR = bulletRR.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidC = bulletC.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidLL = bulletLL.GetComponent<Rigidbody2D>();
                rigidRR.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidC.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidLL.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 4:
                GameObject bulletR2 = Instantiate(bulletObjB, transform.position + Vector3.right * 0.35f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletCC = Instantiate(bulletObjA, transform.position, transform.rotation);
                GameObject bulletL2 = Instantiate(bulletObjB, transform.position + Vector3.left * 0.35f, transform.rotation);
                Rigidbody2D rigidR2 = bulletR2.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidCC = bulletCC.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL2 = bulletL2.GetComponent<Rigidbody2D>();
                rigidR2.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidCC.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL2.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 5:
                GameObject bulletR3 = Instantiate(bulletObjB, transform.position + Vector3.right * 0.35f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletC3 = Instantiate(bulletObjB, transform.position, transform.rotation);
                GameObject bulletL3 = Instantiate(bulletObjB, transform.position + Vector3.left * 0.35f, transform.rotation);
                Rigidbody2D rigidR3 = bulletR3.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidC3 = bulletC3.GetComponent<Rigidbody2D>();
                Rigidbody2D rigidL3 = bulletL3.GetComponent<Rigidbody2D>();
                rigidR3.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidC3.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                rigidL3.AddForce(Vector2.up * 10, ForceMode2D.Impulse);
                break;
            case 6:
                GameObject bulletR4 = Instantiate(bulletObjB, transform.position + Vector3.right * 0.35f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletRR4 = Instantiate(bulletObjA, transform.position + Vector3.right * 0.7f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletC4 = Instantiate(bulletObjB, transform.position, transform.rotation);
                GameObject bulletL4 = Instantiate(bulletObjB, transform.position + Vector3.left * 0.35f, transform.rotation);
                GameObject bulletLL4 = Instantiate(bulletObjA, transform.position + Vector3.left * 0.7f, transform.rotation);
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
                GameObject bulletR5 = Instantiate(bulletObjB, transform.position + Vector3.right * 0.35f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletRR5 = Instantiate(bulletObjB, transform.position + Vector3.right * 0.7f, transform.rotation); //Destroy�� �ݴ�, ����
                GameObject bulletC5 = Instantiate(bulletObjB, transform.position, transform.rotation);
                GameObject bulletL5 = Instantiate(bulletObjB, transform.position + Vector3.left * 0.35f, transform.rotation);
                GameObject bulletLL5 = Instantiate(bulletObjB, transform.position + Vector3.left * 0.7f, transform.rotation);
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
        curShotDelay += Time.deltaTime; //������ ������ Time.deltaTime�� ��� ���Ͽ� �ð����

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
        manager.UpdateBoomIcon(boom);

        //#1.Effect visible
        boomEffect.SetActive(true);
        Invoke("OffBoomEffect", 3);

        //#2.Remove Enemy
        GameObject[] enemies = GameObject.FindGameObjectsWithTag("Enemy");
        for (int index = 0; index < enemies.Length; index++)
        {
            Enemy enemyLogic = enemies[index].GetComponent<Enemy>();
            enemyLogic.OnHit(1000);
        }

        //#3.Remove EnemyBullet
        GameObject[] bullets = GameObject.FindGameObjectsWithTag("EnemyBullet");
        for (int index = 0; index < bullets.Length; index++)
        {
            Destroy(bullets[index]);
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
            manager.UpdateLifeIcon(life);

            if(life == 0)
            {
                manager.GameOver();
            }
            else
            {
                manager.RespawnPlayer();
            }
            gameObject.SetActive(false);
            Destroy(collision.gameObject);
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
                        manager.UpdateBoomIcon(boom);
                    }
                    break;
            }
            Destroy(collision.gameObject);
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
