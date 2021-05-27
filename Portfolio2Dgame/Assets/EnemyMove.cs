using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMove : MonoBehaviour
{
    Rigidbody2D rigid; //적 AI
    SpriteRenderer spriteRenderer; //방향 전환을 위한 spriterenderer
    Animator anim; //애니메이션 효과
    public int nextMove; //int형으로 AI움직임 속도를 위한 변수 public으로 선언해서 unity 안에서 확인 가능
    CapsuleCollider2D capCollider;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>(); //초기화
        spriteRenderer = GetComponent<SpriteRenderer>(); //초기화
        anim = GetComponent<Animator>(); //초기화
        capCollider = GetComponent<CapsuleCollider2D>();
        Think(); //시작하자마자 이동시에 애니메이션이 발동해야하기때문에 Think();함수를 먼저 적는다.
        Invoke("Think", 5); //시작과 동시에 Think함수 실행시켜주는데 딜레이 없이 재귀함수로 돌리면 에러가 발생할수 있어서 딜레이를 만들어주는게 바로 Invoke, Think함수를 5초 뒤에
    }
    void FixedUpdate()
    {
        //무빙
        rigid.velocity = new Vector2(nextMove, rigid.velocity.y);

        //낭떠러지로 떨어지지 않게 ray설정
        Vector2 frontVec = new Vector2(rigid.position.x + nextMove * 0.3f, rigid.position.y); //레이 선을 가운데가 아닌 바라보는 방향 쪽으로 이동 new Vector2설정으로 x축에 + 앞뒤(nextMove)*0.3f(간격을 더 좁게)
        Debug.DrawRay(frontVec, Vector3.down, new Color(0, 1, 0)); //Debug로 레이선을 보여준다(레이가 있어야할 포지션, 어느 방향, 색깔)
        RaycastHit2D rayHit = Physics2D.Raycast(frontVec, Vector3.down, 2, LayerMask.GetMask("Platform"));//가는 방향 앞에 ray, 아래로, 레이선 길이 2밑으로 하면 내리막길이 레이선이 짧아서 인식을 못해서 못내려가기 때문에 2로 증가, 플랫폼 layer

        if (rayHit.collider == null) //레이선이 아래로 치는게 없으면
            Turn(); //돌아가는함수
    }

    void Think()
    {
        //다음 행동패턴
        nextMove = Random.Range(-1, 2); //-1에서 1사이로 랜덤
        
        //AI의 이동 애니메이션을 int형으로 해서 0일때, 같지 않을때로 설정했기 때문에 그거에 대한 초기화
        anim.SetInteger("WalkSpd", nextMove); //애니메이션 WalkSpd가 nextMove이다 설정

        //방향 전환
        if (nextMove != 0) //0이 아니고 움직일때 방향 전환
            spriteRenderer.flipX = nextMove == -1; //원래는 오른쪽을 보는 스프라이트라 왼쪽으로 가면 플립 작동하게 -1

        float nextThinkTime = Random.Range(2f, 5f); //좌우 이동하는 빈도를 2초에서 5초 사이로 바뀌는걸 랜덤으로 설정
        Invoke("Think", nextThinkTime); //재귀함수로 왔다갔다 하는걸 2~5초 후 다시 발동
    }

    void Turn()
    {
        nextMove *= -1; //반대로 돌자
        spriteRenderer.flipX = nextMove == -1; //방향전환
        CancelInvoke(); //생각하던거 멈추고
        Invoke("Think", 5); //다시 생각
    }
    public void OnDamaged()
    {
        spriteRenderer.color = new Color(1, 1, 1, 0.4f); //적의 색 투명화
        spriteRenderer.flipY = true; //거꾸로 뒤집기
        capCollider.enabled = false; //고체화 해제하여 중력은 그대로 아래로 떨어짐
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //피격시 살짝 뜸
        Invoke("DeActive", 5); //5초 뒤에 실행
    }
    void DeActive()
    {
        gameObject.SetActive(false); //적 오브젝트 비활성화 시켜서 없게 만듬
    }
}


