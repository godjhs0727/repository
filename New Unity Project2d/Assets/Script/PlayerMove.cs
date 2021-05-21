using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public GameManager gameManager;
    public float maxSpeed; //public���� �ָ� unity�� inspector â�� ����
    public float jump;
    Rigidbody2D rigid;
    SpriteRenderer spriteRenderer;
    Animator anim;
    CapsuleCollider2D capCollider;
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>(); //rigid������
        //���� *Rigidbody2D���� Freeze Z�� üũ���־�� �ȳѾ�����. ������Ʈ ȸ���� �󸮴� �ɼ�
        spriteRenderer = GetComponent<SpriteRenderer>(); //�ʱ�ȭ
        capCollider = GetComponent<CapsuleCollider2D>();
        anim = GetComponent<Animator>();
    }

    void Update()
    {
        //Jump
        if (Input.GetButtonUp("Jump") && !anim.GetBool("isJumping")) //��ư ���� //Jump�� SpaceŰ, Edit ProjectSetting InputManager���� Ȯ�� ����
        {
            rigid.AddForce(Vector2.up * jump, ForceMode2D.Impulse);
            //animation ������
            anim.SetBool("isJumping", true);
        }
        //Linear Drag�� ���������� 2�� ���� ���� �ӵ��� ������ �ְ� ���߰� �Ѵ�.
        //���⶧ �ӵ�
        if (Input.GetButtonUp("Horizontal")) //��ư ����
        {
            rigid.velocity = new Vector2(rigid.velocity.normalized.x * 0.5f, rigid.velocity.y);
            //normalized�� vector��, �׷��� ����� x, 1������ ����� �ش�.
        }

        //���� ��ȯ
        if (Input.GetButton("Horizontal"))
        {
            spriteRenderer.flipX = Input.GetAxisRaw("Horizontal") == -1;
        }
        
        //Animation
        if(Mathf.Abs(rigid.velocity.x) < 0.3) //MathfŬ����.Abs���밪
        {
            anim.SetBool("isWalking", false);
        }
        else
        {
            anim.SetBool("isWalking", true);
        }
    }
    void FixedUpdate()
    {
        //�����̴� ��Ʈ��, �Ϲ����� �̵� ���
        float h = Input.GetAxisRaw("Horizontal");
        rigid.AddForce(Vector2.right * h, ForceMode2D.Impulse); //rigid�� �� �ֱ�

        //������ �ִ¸�ŭ ���ӷ��� ��� �ٱ� ������ �Ѱ谪�� �����ش�, velocity�� �ӷ�
        //�ִ� �ӵ� ����
        if (rigid.velocity.x > maxSpeed) //������
            rigid.velocity = new Vector2(maxSpeed, rigid.velocity.y); // Vector2(x��, y��)
        else if (rigid.velocity.x < maxSpeed * (-1)) //����
            rigid.velocity = new Vector2(maxSpeed * (-1), rigid.velocity.y); // Vector2(x��, y��)

        //RayCast : ������Ʈ �˻��� ���� Ray�� ��� ���
        //Landing platform
        if (rigid.velocity.y < 0)
        {
            Debug.DrawRay(rigid.position, Vector3.down, new Color(0, 1, 0)); //Debug�̱� ������ ���� ���ӿ����� ������ ����

            RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, Vector3.down, 1, LayerMask.GetMask("Platform")); //Ray�� �Ʒ��� ��°�
                                                                                                                     //GetMask() : ���̾� �̸��� �ش��ϴ� �������� �����ϴ� �Լ�
                                                                                                                     //��Ʈ�� ������ layermask�� �ش��ϴ� �͵鸸 ��ĵ�Ѵ�.
            if (rayHit.collider != null) // ���� ���� �¾Ҵٸ�
            {
                if (rayHit.distance < 0.5f) //�÷��̾��� ���� ��ŭ �����ͼ� �ٴڿ� ����� ���
                {
                    anim.SetBool("isJumping", false);
                }
            }
        }
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.tag == "Enemy")
        {
            //Attack
            if (rigid.velocity.y < 0 && transform.position.y > collision.transform.position.y)
            {
                OnAttack(collision.transform);
            }
            else
                OnDamaged(collision.transform.position);
        }
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.tag == "Item")
        {
            bool isBronze = collision.gameObject.name.Contains("Bronze");
            bool isSilver = collision.gameObject.name.Contains("Silver");
            bool isGold = collision.gameObject.name.Contains("Gold");

            if (isBronze)
                gameManager.stagePoint += 50;
            else if (isSilver)
                gameManager.stagePoint += 100;
            else if (isGold)
                gameManager.stagePoint += 300;
            //Point
            gameManager.stagePoint += 100;
            //Deactive Item
            collision.gameObject.SetActive(false);
        }
        else if(collision.gameObject.tag == "Finish")
        {
            //Next Stage
            gameManager.NextStage();
        }
    }
    void OnAttack(Transform enemy)
    {
        //Point
        gameManager.stagePoint += 100;
        //Reaction Force
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse);
        //Enemy Die
        EnemyMove enemyMove = enemy.GetComponent<EnemyMove>();
        enemyMove.OnDamaged();
    }

    void OnDamaged(Vector2 targetPos) //collision2D�� Vector2 ��
    {
        //Health Down
        gameManager.HealthDown();
        //layer ���� ��ȣ
        gameObject.layer = 11;
        //��������Ʈ �� RGB ���� 4��° ����
        spriteRenderer.color = new Color(1, 1, 1, 0.4f);
        //ƨ�ܳ����°� Reaction Force
        //ȣ���Ҷ� new���
        int dirc = transform.position.x - targetPos.x > 0 ? 1 : -1;
        rigid.AddForce(new Vector2(dirc, 1) * 7, ForceMode2D.Impulse);

        //Animation
        anim.SetTrigger("doDamaged");

        Invoke("OffDamaged", 3);

    }

    void OffDamaged()
    {
        gameObject.layer = 10;
        spriteRenderer.color = new Color(1, 1, 1, 1);
    }

    public void OnDie()
    {
        //Sprite Alpha
        spriteRenderer.color = new Color(1, 1, 1, 0.4f);
        //Sprite Flip Y
        spriteRenderer.flipY = true;
        //Collider Disable
        capCollider.enabled = false;
        //Die Effect Jump
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse);
    }
    public void VelocityZero()
    {
        rigid.velocity = Vector2.zero;
    }
}
