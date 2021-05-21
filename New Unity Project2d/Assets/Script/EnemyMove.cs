using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMove : MonoBehaviour
{
    Rigidbody2D rigid;
    public int nextMove; //�ൿ��ǥ�� ������ ���� �ϳ� ����
    SpriteRenderer spriteRenderer;
    Animator anim;
    CapsuleCollider2D capCollider;
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        anim = GetComponent<Animator>();
        capCollider = GetComponent<CapsuleCollider2D>();
        Think();
        Invoke("Think", 5);//5�ʵڿ� ������
    }
    void FixedUpdate()
    {
        //Move
        rigid.velocity = new Vector2(nextMove, rigid.velocity.y);

        //Platform Check
        Vector2 frontVec = new Vector2(rigid.position.x + nextMove * 0.2f, rigid.position.y);
        Debug.DrawRay(frontVec, Vector3.down, new Color(0, 1, 0)); //Debug�̱� ������ ���� ���ӿ����� ������ ����
        RaycastHit2D rayHit = Physics2D.Raycast(frontVec, Vector3.down, 1, LayerMask.GetMask("Platform")); //Ray�� �Ʒ��� ��°�
                                                                                                           //GetMask() : ���̾� �̸��� �ش��ϴ� �������� �����ϴ� �Լ�
                                                                                                           //��Ʈ�� ������ layermask�� �ش��ϴ� �͵鸸 ��ĵ�Ѵ�.
        if (rayHit.collider == null) // ���� ���� �¾Ҵٸ�
            Return();
    }

    void Think()
    {
        //Set Next Active
        nextMove = Random.Range(-1, 2);//�ּҰ��� �������� ������ �Ǵµ� �ִ밪�� �������� ������ �ȵǾ 1�� ���� 2        

        //Sprite Animation
        anim.SetInteger("RunSpeed", nextMove);

        //Flip Sprite
        if (nextMove != 0)
            spriteRenderer.flipX = nextMove == 1;

        //Recursive ���
        float nextThinkTime = Random.Range(2f, 5f);
        Invoke("Think", nextThinkTime);
    }
    void Return()
    {
        nextMove *= -1;
        spriteRenderer.flipX = nextMove == 1;

        CancelInvoke();
        Invoke("Think", 2);
    }

    public void OnDamaged()
    {
        //Sprite Alpha
        spriteRenderer.color = new Color(1, 1, 1, 0.4f);
        //Sprite Flip Y
        spriteRenderer.flipY = true;
        //Collider Disable
        capCollider.enabled = false;
        //Die Effect Jump
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse);
        //Destroy
        Invoke("DeActive", 5);
    }

    void DeActive()
    {
        gameObject.SetActive(false);
    }
}
