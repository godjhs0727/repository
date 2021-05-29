using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    Rigidbody2D rigid;
    public AudioClip audioBullet;
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
    }
    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Platform")
        {
            Destroy(gameObject);
        }
        else if (collision.gameObject.tag == "SpikeEnemy")
        {
            OnAttack(collision.transform);            
            Destroy(gameObject);
        }
    }
    void OnAttack(Transform enemy)
    {
        rigid.AddForce(Vector2.up * 5, ForceMode2D.Impulse); //피격 성공시 플레이어가 살짝 뜬다.
        EnemyMove enemyMove = enemy.GetComponent<EnemyMove>(); //EnemyMove스크립트를 사용하기 위해 초기화
        enemyMove.OnDamaged(); //EnemyMove 스크립트의 public화 된 함수를 가져옴
    }
}