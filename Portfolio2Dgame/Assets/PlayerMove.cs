using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public GameObject bulletObj;
    public GameManager gameManager;
    Rigidbody2D rigid; //rigid �÷��̾�
    SpriteRenderer spriteRenderer; //���� ��ȯ�ϱ� ���� spriterenderer flip
    Animator anim; //�ִϸ��̼� ȿ��
    CapsuleCollider2D capCollider;
    float maxSpeed = 3; //���ǵ带 �⺻ 3���� ���� ������ ���ϸ� ���� ���� �س��� ����Ƽ �ȿ��� ���氡��
    public float JumpPower; //����Ƽ���� ���� ó�� default 0
    void Awake() //�ʱ�ȭ �ϱ� ���� Awake
    {
        rigid = GetComponent<Rigidbody2D>(); //�ʱ�ȭ
        spriteRenderer = GetComponent<SpriteRenderer>(); //�ʱ�ȭ
        anim = GetComponent<Animator>(); //�ʱ�ȭ
        capCollider = GetComponent<CapsuleCollider2D>();
    }
    void Update()
    {
        //����
        if (Input.GetButtonUp("Jump") && !anim.GetBool("isJumping")) //Jump�� ������Ʈ ���� input���� space�� �̱⿡ ���� �����̽� �� �������� ���� �׸��� �ִϸ��̼��� jumping ���� �ƴ� �����϶�
        {
            rigid.AddForce(Vector2.up * JumpPower, ForceMode2D.Impulse); //AddForce�� ���� ���Ѵ� Vector2�� ���� JumpPower��ŭ �ø��� ForceMode2D.Impulse
            anim.SetBool("isJumping", true); //�ִϸ��̼� isJumping �� true
        }

        //���⶧�� �������� �ٴ��� ������ 0���� �����Ǿ��ֱ⿡ ���⶧ ���� �̲������� �� �̲������� ���� ����
        if(Input.GetButtonUp("Horizontal")) //Horizontal�� projectSetting Input���� ����Ű �̱⿡ positive�� ������ �ݴ�� ����
        {
            rigid.velocity = new Vector2(rigid.velocity.normalized.x * 0.5f, rigid.velocity.y); //rigid.velocity�� �ӵ�, normalized�� ����ũ�⸦ 1�� ���� �����̰� 0.5���ؼ� �� õõ��,
            //�Ҽ��� �ڿ� �ݵ�� f��������Ѵ�.
        }
        //������ȯ
        if(Input.GetButton("Horizontal")) //ȭ��ǥ �¿츦 ������, ��ư�� ������ ���� �������
        {
            spriteRenderer.flipX = Input.GetAxisRaw("Horizontal") == -1; //���� ��ȯ�Ҷ� ��������Ʈ �׸��� �¿� X�� �������� �ٲ��.
        }   
        if(Input.GetButtonUp("Fire1"))
        {
            if (spriteRenderer.flipX)
            {
                Fire();
            }
            else
            {
                GameObject bullet = Instantiate(bulletObj, transform.position, transform.rotation);
                Rigidbody2D rigid = bullet.GetComponent<Rigidbody2D>();
                rigid.AddForce(Vector2.right * 5, ForceMode2D.Impulse);

            }
        }
    }
    void Fire()
    {
        GameObject bullet = Instantiate(bulletObj, transform.position, transform.rotation);
        Rigidbody2D rigid = bullet.GetComponent<Rigidbody2D>();
        rigid.AddForce(Vector2.right * (-5), ForceMode2D.Impulse);
    }
    void FixedUpdate()
    {
        //�̵�����
        float h = Input.GetAxisRaw("Horizontal"); //ȭ��ǥ �¿� ���� positive = ������ �ݴ�� ����
        rigid.AddForce(Vector2.right * h, ForceMode2D.Impulse); //�������� �̵��Ѵ�.

        //�ӵ� ���ӷ� ���� �׳� �θ� ��� �ӵ��� �����ع���, ���� �ӵ� ����
        if (rigid.velocity.x > maxSpeed) //���� x�� �ӵ��� maxSpeed���� ũ��  ����� ������ �κ�
            rigid.velocity = new Vector2(maxSpeed, rigid.velocity.y); //���ǵ�� maxSpeed
        else if (rigid.velocity.x < maxSpeed * (-1)) //���� �κ��̱⿡ -1 ������
            rigid.velocity = new Vector2(maxSpeed * (-1), rigid.velocity.y); //���������� -maxSpeed��
        
        //�ȱ� �ִϸ��̼�
        if (Mathf.Abs(rigid.velocity.x) < 0.3) //mathfŬ������ ����Ͽ� Abs�� ���밪 ��� �������̵� �����̵� �ӵ��� 0.3���� ������
            anim.SetBool("isWalking", false); //�ȴ� �ִϸ��̼� ȿ�� ����
        else
            anim.SetBool("isWalking", true); //�ߵ�

        //�������� ����
        if (rigid.velocity.y < 0) //�����ϰ� ���� �������ϱ� �Ʒ��� ���� �ӵ��� ������ ���̳ʽ�
        {
            Debug.DrawRay(rigid.position, Vector3.down, new Color(0, 1, 0)); //Debug�� gameȭ�鿣 �ȳ����� Sceneȭ������ Ȯ�� �Ҽ� �ִ�. ������ �÷��̾��� ��ġ���� �Ʒ��� �ʷϻ� ���� ���.
            RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, Vector3.down, LayerMask.GetMask("Platform")); //���� ������ ��ǥ���� ������. �÷��̾, �Ʒ���, layer�� Platform�ΰſ� ����

            if(rayHit.collider != null) //���� ��ü�� �¾Ҵٸ�
            {
                if(rayHit.distance < 0.5) //������ 0.5�Ʒ��� ���� �ִϸ��̼��� ������Ų��.                
                    anim.SetBool("isJumping", false);              
            }
        }
    }
    void OnCollisionEnter2D(Collision2D collision) //�ǰݽ�
    {
        if (collision.gameObject.tag == "Enemy") //Enemy tag�� ���� collider�� ���� ��ü�� ���˽�
        {
            if (rigid.velocity.y < 0 && transform.position.y > collision.transform.position.y) //�÷��̾ �����Ҷ�, �׸��� �ǰݴ���� y�������� �浹�������� Ŀ����
            {
                OnAttack(collision.transform);
            }
            else
            {
                if (gameManager.health < 2)
                    OnDie();
                else
                    OnDamaged(collision.transform.position); //������ �Լ� ȣ��(�÷��̾ ���� collider)
            }
        }
        else if(collision.gameObject.tag == "SpikeEnemy")
        {
            if (gameManager.health < 2)
                OnDie();
            else
                OnDamaged(collision.transform.position);
        }
    }
    void OnTriggerEnter2D(Collider2D collision)
    {
        capCollider.isTrigger = true;
        if (collision.tag == "Ring")
        {
            gameManager.stagePoint += 100;
            collision.gameObject.SetActive(false);
            
        }
        else if (collision.tag == "Finish")
        {
            gameManager.NextStage();
        }

    }
    void OnTriggerExit2D(Collider2D collision)
    {
        capCollider.isTrigger = false;   
    }
    void OnAttack(Transform enemy)
    {
        gameManager.stagePoint += 100;
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //�ǰ� ������ �÷��̾ ��¦ ���.
        EnemyMove enemyMove = enemy.GetComponent<EnemyMove>(); //EnemyMove��ũ��Ʈ�� ����ϱ� ���� �ʱ�ȭ
        enemyMove.OnDamaged(); //EnemyMove ��ũ��Ʈ�� publicȭ �� �Լ��� ������
    }
    void OnDamaged(Vector2 targetPos) //(Enter2D�̱� ������ Vector2), ���� ����
    {
        //Health Down
        gameManager.HealthDown();
        gameObject.layer = 8; //Player���� ������Ʈ�� ���̾ 8������ ����, 8���� PlayerDamaged�ε� project���ÿ��� Enemy�� �浹 ���ϰ� �����س��� ������ ��������
        
        //�� ����
        spriteRenderer.color = new Color(1, 1, 1, 0.4f); //�ڿ� 4��°�� ����

        //������ ƨ�ܳ���
        int dirc = transform.position.x/*���� ���� �׷��ϱ� �÷��̾�*/ - targetPos.x > 0 ? 1 : -1; //���׿�����, ����� 1, ������ -1, ������ �÷��̾ �����ʿ� �ְ� ������ �ݴ�
        rigid.AddForce(new Vector2(dirc, 1) * 7, ForceMode2D.Impulse); //��ü�� ���� �޴´�

        anim.SetTrigger("Damage"); //Ʈ���� �Ķ���ͷ� ���Ҵ�. ������ �ߵ��ϴ� anystate �ִϸ��̼�, anystate�� � �ִϸ��̼��� �۵��ϴ����� ���� ���� ��ų�� ����
        Invoke("OffDamaged", 5); //3�ʵڿ� �Լ��� �ҷ��� ���������´� 3�ʰ��� ���� ���Ŀ� �������
    }
    void OffDamaged()
    {
        gameObject.layer = 7; //7��° Player layer�� �ٽ� ���ƿ���
        spriteRenderer.color = new Color(1, 1, 1, 1); //���� ����
    }
        
    public void OnDie()
    {
        anim.SetTrigger("Fall");
        Time.timeScale = 0;
        //spriteRenderer.color = new Color(1, 1, 1, 0.4f); 
        //spriteRenderer.flipY = true; //�Ųٷ� ������
        capCollider.enabled = false; //��üȭ �����Ͽ� �߷��� �״�� �Ʒ��� ������
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //��¦ ��
    }
    public void VelocityZero()
    {
        rigid.velocity = Vector2.zero;
    }

}
