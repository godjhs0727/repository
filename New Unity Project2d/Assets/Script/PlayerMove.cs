using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public float maxSpeed; //public���� �ָ� unity�� inspector â�� ����
    public float jump;
    Rigidbody2D rigid;
    SpriteRenderer spriteRenderer;
    Animator anim;
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>(); //rigid������
        //���� *Rigidbody2D���� Freeze Z�� üũ���־�� �ȳѾ�����. ������Ʈ ȸ���� �󸮴� �ɼ�
        spriteRenderer = GetComponent<SpriteRenderer>(); //�ʱ�ȭ
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
        if (Input.GetButtonDown("Horizontal"))
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
}
