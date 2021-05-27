using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMove : MonoBehaviour
{
    Rigidbody2D rigid; //�� AI
    SpriteRenderer spriteRenderer; //���� ��ȯ�� ���� spriterenderer
    Animator anim; //�ִϸ��̼� ȿ��
    public int nextMove; //int������ AI������ �ӵ��� ���� ���� public���� �����ؼ� unity �ȿ��� Ȯ�� ����
    CapsuleCollider2D capCollider;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>(); //�ʱ�ȭ
        spriteRenderer = GetComponent<SpriteRenderer>(); //�ʱ�ȭ
        anim = GetComponent<Animator>(); //�ʱ�ȭ
        capCollider = GetComponent<CapsuleCollider2D>();
        Think(); //�������ڸ��� �̵��ÿ� �ִϸ��̼��� �ߵ��ؾ��ϱ⶧���� Think();�Լ��� ���� ���´�.
        Invoke("Think", 5); //���۰� ���ÿ� Think�Լ� ��������ִµ� ������ ���� ����Լ��� ������ ������ �߻��Ҽ� �־ �����̸� ������ִ°� �ٷ� Invoke, Think�Լ��� 5�� �ڿ�
    }
    void FixedUpdate()
    {
        //����
        rigid.velocity = new Vector2(nextMove, rigid.velocity.y);

        //���������� �������� �ʰ� ray����
        Vector2 frontVec = new Vector2(rigid.position.x + nextMove * 0.3f, rigid.position.y); //���� ���� ����� �ƴ� �ٶ󺸴� ���� ������ �̵� new Vector2�������� x�࿡ + �յ�(nextMove)*0.3f(������ �� ����)
        Debug.DrawRay(frontVec, Vector3.down, new Color(0, 1, 0)); //Debug�� ���̼��� �����ش�(���̰� �־���� ������, ��� ����, ����)
        RaycastHit2D rayHit = Physics2D.Raycast(frontVec, Vector3.down, 2, LayerMask.GetMask("Platform"));//���� ���� �տ� ray, �Ʒ���, ���̼� ���� 2������ �ϸ� ���������� ���̼��� ª�Ƽ� �ν��� ���ؼ� ���������� ������ 2�� ����, �÷��� layer

        if (rayHit.collider == null) //���̼��� �Ʒ��� ġ�°� ������
            Turn(); //���ư����Լ�
    }

    void Think()
    {
        //���� �ൿ����
        nextMove = Random.Range(-1, 2); //-1���� 1���̷� ����
        
        //AI�� �̵� �ִϸ��̼��� int������ �ؼ� 0�϶�, ���� �������� �����߱� ������ �װſ� ���� �ʱ�ȭ
        anim.SetInteger("WalkSpd", nextMove); //�ִϸ��̼� WalkSpd�� nextMove�̴� ����

        //���� ��ȯ
        if (nextMove != 0) //0�� �ƴϰ� �����϶� ���� ��ȯ
            spriteRenderer.flipX = nextMove == -1; //������ �������� ���� ��������Ʈ�� �������� ���� �ø� �۵��ϰ� -1

        float nextThinkTime = Random.Range(2f, 5f); //�¿� �̵��ϴ� �󵵸� 2�ʿ��� 5�� ���̷� �ٲ�°� �������� ����
        Invoke("Think", nextThinkTime); //����Լ��� �Դٰ��� �ϴ°� 2~5�� �� �ٽ� �ߵ�
    }

    void Turn()
    {
        nextMove *= -1; //�ݴ�� ����
        spriteRenderer.flipX = nextMove == -1; //������ȯ
        CancelInvoke(); //�����ϴ��� ���߰�
        Invoke("Think", 5); //�ٽ� ����
    }
    public void OnDamaged()
    {
        spriteRenderer.color = new Color(1, 1, 1, 0.4f); //���� �� ����ȭ
        spriteRenderer.flipY = true; //�Ųٷ� ������
        capCollider.enabled = false; //��üȭ �����Ͽ� �߷��� �״�� �Ʒ��� ������
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //�ǰݽ� ��¦ ��
        Invoke("DeActive", 5); //5�� �ڿ� ����
    }
    void DeActive()
    {
        gameObject.SetActive(false); //�� ������Ʈ ��Ȱ��ȭ ���Ѽ� ���� ����
    }
}


