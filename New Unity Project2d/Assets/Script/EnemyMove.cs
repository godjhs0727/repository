using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMove : MonoBehaviour
{
    Rigidbody2D rigid;
    public int nextMove; //행동지표를 결정할 변수 하나 생성
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
        Invoke("Think", 5);//5초뒤에 딜레이
    }
    void FixedUpdate()
    {
        //Move
        rigid.velocity = new Vector2(nextMove, rigid.velocity.y);

        //Platform Check
        Vector2 frontVec = new Vector2(rigid.position.x + nextMove * 0.2f, rigid.position.y);
        Debug.DrawRay(frontVec, Vector3.down, new Color(0, 1, 0)); //Debug이기 때문에 실제 게임에서는 보이지 않음
        RaycastHit2D rayHit = Physics2D.Raycast(frontVec, Vector3.down, 1, LayerMask.GetMask("Platform")); //Ray를 아래로 쏘는거
                                                                                                           //GetMask() : 레이어 이름에 해당하는 정수값을 리턴하는 함수
                                                                                                           //히트는 오로지 layermask에 해당하는 것들만 스캔한다.
        if (rayHit.collider == null) // 빔을 쏴서 맞았다면
            Return();
    }

    void Think()
    {
        //Set Next Active
        nextMove = Random.Range(-1, 2);//최소값은 랜덤값에 포함이 되는데 최대값은 랜덤값에 포함이 안되어서 1더 많은 2        

        //Sprite Animation
        anim.SetInteger("RunSpeed", nextMove);

        //Flip Sprite
        if (nextMove != 0)
            spriteRenderer.flipX = nextMove == 1;

        //Recursive 재귀
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
